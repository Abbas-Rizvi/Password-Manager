# include <stdio.h>
# include <fstream>
# include <string>
# include <sqlite3.h>
# include "../include/generate.h"

int main(){

    generate newSite(true, true, true, 15);

    newSite.writePass();

    return 0;
}
