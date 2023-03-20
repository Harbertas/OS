# OS
Labaratory tasks for OM course 

## Downloading and starting:

```console
> go to the folder "OS_LAB_2"
> go to the folder "OSLAB2_DLL_CLIENT_SETUP/Release"
> download one of the available files "OSLAB2_DLL_CLIENT_SETUP.msi" or "setup.exe"
> install the program
> start the program
```

## Using:

```console
----------------------------------------
Here are the list of all available commands:
----------------------------------------
Enter a Number To Open One of The control panel components
 1 - Display
 2 - Security
 3 - Power
 4 - Storage
 5 - Update
 0 - exit
----------------------------------------
```

## How it works

After exiting, application will create folder named "OS_LAB_2" in the path "C://Users//%USERNAME%//"

Then it will create a folder structure similar to this:

```console
                                   OS_LAB_2
                                      |
                                      |
                                     / \
                                    /   \
                                 Klangauskas
                                /     |     \
                               /      |      \
                              /       |       \
                  Klangauskas1  Klangauskas2   Klangauskas3
                 /      |     \        |             |
                /       |      \       |             |
               /        |       \   Have the same folders as Klangauskas1
              /         |        \
Klangauskas1Hubertas1   |  Klangauskas1Hubertas3
                        |
             Klangauskas1Hubertas2
```

Then it will create files "example.txt" in each directory

Then it will do some computations and write each result into those files in the sequence like this

```console
klangauskas -> example.txt;
klangauskas -> klangaskas1 -> example.txt;
klangauskas -> klangaskas2 -> example.txt;
klangauskas -> klangaskas3 -> example.txt;
klangauskas -> klangaskas1 -> klangauskas1Hubertas1 -> example.txt;
klangauskas -> klangaskas1 -> klangauskas1Hubertas2 -> example.txt;
klangauskas -> klangaskas1 -> klangauskas1Hubertas3 -> example.txt;
klangauskas -> klangaskas2 -> klangauskas1Hubertas1 -> example.txt;
klangauskas -> klangaskas2 -> klangauskas1Hubertas2 -> example.txt;
klangauskas -> klangaskas2 -> klangauskas1Hubertas3 -> example.txt;
klangauskas -> klangaskas3 -> klangauskas1Hubertas1 -> example.txt;
klangauskas -> klangaskas3 -> klangauskas1Hubertas2 -> example.txt;
klangauskas -> klangaskas3 -> klangauskas1Hubertas3 -> example.txt;
...
Starts from klangauskas -> example.txt again.
```

Then it will merge those results based on the F input (F = [-2..2]) and save them into the **Klangauskas** directory in files **F.txt**

Then it will delete all the subdirectories from Klangauskas recursively
