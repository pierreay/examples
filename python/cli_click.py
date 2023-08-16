#!/usr/bin/env python3

import click

@click.command()
@click.argument("message")
@click.option("--count", default=1, help="Number of greetings.")
@click.option("--name", prompt="Your name", help="The person to greet.")
def hello(message, count, name):
    """Simple program that greets NAME for a total of COUNT times using MESSAGE."""
    for _ in range(count):
        click.echo("{}, {}!".format(message, name))

if __name__ == '__main__':
    hello()
