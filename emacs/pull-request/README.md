# pull-request

Test an Emacs package for an issue or a pull-request.

This is an example of how a package can be tested in Emacs using a minimal
working example. In this example, the `ox-bb` package is tested on its
`link-with-id` development branch.

## Usage

First, clone the repository:

``` bash
make clone
```

Second, run Emacs using the minimal `init.el` initialization file:

``` bash
make run
```

It will open the minimal working example `mwe.org`, which can be used to the
package.
