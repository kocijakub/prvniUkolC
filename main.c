#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct User{
    char * jmeno;
    char * prijmeni;
    char * email;
    int vek;
};
struct User createUser(char * jmeno, char * prijmeni,char * email, int vek){
    struct User temp;
    temp.jmeno = jmeno;
    temp.prijmeni = prijmeni;
    temp.email = email;
    temp.vek = vek;
    return temp;
}

int main (){
    struct User * users[30] = {NULL};
    int numOfUsers = 0;
    int jmenoS,prijmeniS,emailS;
    int vek;
    struct User * fuser = (struct User *)malloc(sizeof(struct User));
    *fuser = createUser("jakub","koci","gmail",18);
    users[0] = fuser;
    while(true){
        printf("[0] - vytvor uzivatele\n[1] - odeber uzivatele\n[2] - vypis vsechny uzivatele\n[3] - exit");
        int input;
        scanf("\n%d",&input);
        switch(input){
            case 0:
                if(numOfUsers != 30){
                    printf("%s","napis velikost a nazev jmena:");
                    scanf("%d",&jmenoS);
                    char * name = malloc(sizeof(char) * jmenoS + 1);
                    scanf("%s", name);

                    printf("%s","napis velikost a nazev prijmeni");
                    scanf("%d",&prijmeniS);
                    char * lastName = malloc(sizeof(char) * prijmeniS + 1);
                    scanf("%s",lastName);

                    printf("%s","napis velikost a nazev emailu");
                    scanf("%d",&emailS);
                    char * email = malloc(sizeof(char) * emailS + 1);
                    scanf("%s",email);

                    printf("%s","napis vek:");
                    scanf("%d",&vek);

                    struct User *user = (struct User *)malloc(sizeof(struct User));
                    *user = createUser(name, lastName, email, vek);
                    bool isAdded = false;
                    for(int i = 0; i < 30; i++){
                        if(!isAdded){
                            if(users[i] == NULL){
                                isAdded = true;
                                users[i] = user;
                                numOfUsers++;
                                printf("\nuzivatel byl pridan do seznamu\n");
                                free(user);
                                break;
                            }
                        }
                    }
                }else{
                    printf("maximum uzivatelu, nelze pridat dalsiho");
                }
                break;
            case 1:
                int nameSize;
                printf("napis velikost a jmeno");
                scanf("%d",&nameSize);
                char * name = malloc(sizeof(char) * nameSize + 1);
                scanf("%s",&name);
                for(int i = 0;i < 30; i++){
                    if(strcmp(users[i]->jmeno,name) == 0){
                        users[i] = NULL;
                        numOfUsers--;
                        free(name);
                        printf("\nuzivatel byl smazan\n");
                    }
                }
                printf("\ntento uzivatel neni v seznamu\n");
                break;
            case 2:
                for(int i = 0; i < 30; i++){
                    if(users[i] != NULL){
                        printf("%s\n",users[i]->jmeno);
                    }
                }
                printf("\n");
                break;
            case 3: exit(0);
            default: printf("invalid input,try again");
        }

    }
}
