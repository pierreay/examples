#!/usr/bin/env python3
"""Logging facilities."""

# Core modules.
import logging

# External modules.
import colorlog

# * Objects

# Logger object that can be used accross all modules.
LOGGER = None

# * Constants

# Default logging level for the application.
LOGGER_DEFAULT_LEVEL = "DEBUG"

# * Functions

# ** Configuration

def level_set(level):
    """Set the level of the logging system.

    :param level: The level to set (string or logging's levels).

    """
    LOGGER.setLevel(level)

def level_disable():
    """Disable the logging system."""
    level_set(logging.CRITICAL + 1)

def configure(enable=True, level=LOGGER_DEFAULT_LEVEL):
    """Configure the logging system at runtime.

    :param enable: True to enable the logging system, False to disable it.

    :param level: Level to configure if the system is enabled.

    """
    level_set(level)
    if enable is False:
        level_disable()

# ** Initialization

def init(level):
    """Initialize the logging system.

    If called multiple times, silently exit.

    :param level: The level to use at initialization.

    """
    global LOGGER
    if LOGGER is None:
        # Use a colored StreamHandler.
        handler = colorlog.StreamHandler()
        # Use a colored format depending on the logging level.
        format_debug = "%(log_color)s[%(asctime)s] [%(process)d] [%(threadName)s] [%(module)s] %(levelname)-5s - %(message)s"
        format_info = "%(log_color)s%(levelname)-5s - %(message)s"
        format = format_debug if level == "DEBUG" else format_info
        formatter = colorlog.ColoredFormatter(format)
        # Initialize the Logger object.
        LOGGER = colorlog.getLogger(__name__)
        handler.setFormatter(formatter)
        # NOTE: We want a custom handler and don't want its messages also going
        # to the root handler.
        LOGGER.propagate = False 
        LOGGER.setLevel(level)
        LOGGER.addHandler(handler)

# NOTE: This module will be initialized at import time.
init(LOGGER_DEFAULT_LEVEL)

# * Script

# NOTE: Allows to test the module.
if __name__ == "__main__":
    level_set(logging.INFO)
    LOGGER.info("Hello from a first INFO message!")
    LOGGER.debug("We should not see this message!")
    level_set("DEBUG")
    LOGGER.info("Hello from a second INFO message!")
    LOGGER.debug("Hello from a first DEBUG message!")
    level_disable()
    LOGGER.info("We should not see this message!")
    LOGGER.debug("We should not see this message!")
    level_set("INFO")
    LOGGER.warning("This is a warning!")
    LOGGER.error("This is a not fatal error!")
    LOGGER.critical("This is a fatal error!")
