#include <stdio.h>
#include <stdbool.h>
#include <tgmath.h>

#define LEN 500
void clean_array(int *tab, int n){
    for (int i=0; i<n; i++){
        tab[i]=-1;
    }
}
void value_into_array(int *tab, int n, int value){
    for (int i=0; i<n; i++){
        if (tab[i]==-1)
        {
            tab[i]=value;
            break;
        }
    }
}
void show_array(int *tab, int n){
    for (int i=0; i<n; i++){
        //if (tab[i]!=-1)
            printf("%d ", tab[i]);
    }
    printf("\n");
}
void insert_header_GIF89a_1(int *tab, int n){
    value_into_array(tab, n, 71); //47
    value_into_array(tab, n, 73); //49
    value_into_array(tab, n, 70); //46
    value_into_array(tab, n, 56); //38
    value_into_array(tab, n, 57); //39
    value_into_array(tab, n, 97); //61
}
void insert_size_2(int *tab, int n, int width, int height){
    value_into_array(tab, n, width);
    value_into_array(tab, n, 0);
    value_into_array(tab, n, height);
    value_into_array(tab, n, 0);
} //now we can set up to 255 image size
void insert_packed_byte_3(int *tab, int n) {
    value_into_array(tab, n, 195);
} //now insert 1001 0001: (1)-global color table present, (001)-color resolution, (0)-sort flag, (001)-size of global color table(4)
void insert_background_and_aspect_ratio4(int *tab, int n, int x) {
    value_into_array(tab, n, x);
    value_into_array(tab, n, 0);
}
void insert_global_color_table(int *tab, int n){
    //1
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 0);
    //2
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 30);
    value_into_array(tab, n, 30);
    //3
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 60);
    value_into_array(tab, n, 60);
    //4
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 90);
    value_into_array(tab, n, 90);
    //5
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 120);
    value_into_array(tab, n, 120);
    //6
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 150);
    value_into_array(tab, n, 150);
    //7
    value_into_array(tab, n, 0);//white
    value_into_array(tab, n, 180);
    value_into_array(tab, n, 180);
    //8
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 210);
    value_into_array(tab, n, 210);
    //9
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 220);
    value_into_array(tab, n, 220);
    //10
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 230);
    value_into_array(tab, n, 230);
    //11
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 240);
    value_into_array(tab, n, 240);
    //12
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 250);
    value_into_array(tab, n, 250);
    //13
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 251);
    value_into_array(tab, n, 251);
    //14
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 252);
    value_into_array(tab, n, 252);
    //15
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 253);
    value_into_array(tab, n, 253);
    //16
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 254);
    value_into_array(tab, n, 254);
}
void insert_image_descriptor(int *tab, int n, int w, int h){
    ///*
    value_into_array(tab, n, 33);
    value_into_array(tab, n, 249);
    value_into_array(tab, n, 4);
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 0);

     //*/
    value_into_array(tab, n, 44);

    value_into_array(tab, n, 0); //image left
    value_into_array(tab, n, 0);
    value_into_array(tab, n, 0); //image top
    value_into_array(tab, n, 0);
    //up to 255:
    value_into_array(tab, n, w); //image width
    value_into_array(tab, n, 0);
    value_into_array(tab, n, h); //image height
    value_into_array(tab, n, 0);

    value_into_array(tab, n, 0); //packed field
}
void put_value_to_code_array(int tab[LEN][2], int n, int value, int m){
    int i=0;
    for (i; i<n; i++) if (tab[i][0]==-1) break;  //empty cells are with -1 value
    tab[i][m]=value;
}
int check_if_in_array(int tab[LEN][LEN], int n, int *value, int m){
    bool exists=true;
    printf(" \nsprawdzam\n aktualny stan dictionary:\n");
    for (int i=0; i<39; i++){
        printf("%d:\t", i);
        for (int j=0; j<40; j++){
            if (tab[i][j]!=-1) printf("%d\t", tab[i][j]);
        }
        printf("\n");
    }
    printf("wartosc: ");
    for (int i=0; i<m+1; i++) printf("%d ", value[i]); printf("\n");
    int i;
    for (i=0; i<LEN; i++) {
        exists=true;
        for (int j=0; j<m+1; j++) {
            printf("porownuje %d i %d   |||   ", tab[i][j], value[j]);
            if (!(tab[i][j] == value[j])){
                exists = false;
            }
        }
        if (tab[i][0]==-1) break;
        printf("%s\n", exists ? "true" : "false");
        if(exists==true) {
            printf("\nreturnuje true");
            return i;
        }
    }
    printf("\nreturnuje false");
    return -2;
}

int main () {
    int array_size=5000;
    int arr[array_size];
    clean_array(arr, array_size);

    int w=86;
    int h=86;

    insert_header_GIF89a_1(arr, array_size); //insert header GIF89a:
    insert_size_2(arr, array_size, w, h); //set size of GIF
    insert_packed_byte_3(arr, array_size);
    insert_background_and_aspect_ratio4(arr, array_size, 0);
    insert_global_color_table(arr, array_size); //in this case 16 colors - to be modified
    insert_image_descriptor(arr, array_size, w, h);

    value_into_array(arr, array_size, 4); //original CODEE SIZEEEEE
    value_into_array(arr, array_size, -3);

    //const int data[]={1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1 };
    /*const int data[]={8, 8, 1, 1, 8, 1, 1, 8, 8, 8, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1 ,
                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1 ,
                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1,
                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1  };
   */
    int data[w*h];
    for (int i=0; i<w*h; i++) data[i]=i%16;


    size_t n = sizeof(data)/sizeof(data[0]);
    printf("\nilosc pikseli obrazu: %d\n", n);

    //LZW_encoding(arr, array_size, data, n);

    int current_code_size=5;
    int code[LEN][2];
    for (int i=0; i<LEN; i++) clean_array(code[i], 2);

    code[0][0]=16;
    code[0][1]=current_code_size;

    int dictionary[LEN][LEN];
    for (int i=0; i<LEN; i++) clean_array(dictionary[i], LEN);
    for (int i=0; i<16; i++) dictionary[i][0]=i;
    dictionary[16][0]=-2;
    dictionary[17][0]=-2;

    int buffer[LEN];
    clean_array(buffer, LEN);

    int input_index=0;
    int buffer_index=0;
    int num_in_dictionary=0;

    buffer[0]=data[0];
    input_index += 1;
    buffer_index += 1;
    buffer[buffer_index] = data[input_index];
    while(1) {

        if ((check_if_in_array(dictionary, LEN, buffer, buffer_index))!=-2) { //jesli jest
            input_index += 1;
            buffer_index += 1;
            buffer[buffer_index] = data[input_index];
            printf("\nznalazlem w slowniku\n");
        } else{ //jesli nie ma
            printf("\nnie znalazlem w slowniku, wiec wpisuje \n");
            int i1=0;
            for (i1; i1<LEN; i1++) if (dictionary[i1][0]==-1) break;  //empty cells are with -1 value
            for (int j=0; j<LEN; j++) dictionary[i1][j]=buffer[j];
            num_in_dictionary = i1;
            double cur=(double) current_code_size, two=2;
            printf("\nnum in dictionary: %d, as pow(2, current code size):%f \n", num_in_dictionary, pow(two, cur));
            int how=pow(two, cur);
            printf("  to comparasion: %d  ",how);
            if (num_in_dictionary == how ) current_code_size++;
            printf("  after checking, current code size is: : %d  ",current_code_size);
            put_value_to_code_array(code, LEN, check_if_in_array(dictionary, LEN, buffer, buffer_index-1), 0);
            put_value_to_code_array(code, LEN, current_code_size, 1);
            clean_array(buffer, LEN);
            buffer_index = 0;
            buffer[buffer_index] = data[input_index];
        }
        if (input_index == w*h){
            put_value_to_code_array(code, LEN, check_if_in_array(dictionary, LEN, buffer, buffer_index-1), 0);
            put_value_to_code_array(code, LEN, current_code_size, 1);
            break;
        }
    }

    put_value_to_code_array(code, LEN, 17, 0);
    put_value_to_code_array(code, LEN, current_code_size, 1);
    printf("\n");
    //there is a problem with this cell
    code[1][1]=5; //IMPORTANTTTT - stating code size!!!
    for (int i=0; i<LEN; i++) show_array(code[i], 2);

    //jak to przerobimy na bajty
    int big_arr[LEN*20];
    clean_array(big_arr, LEN*20);
    int pointer=0;
    int i=0;
    while(1){
        int value=code[i][0];
        int code_size=code[i][1];
        for (int j=0; j<code_size; j++){
            big_arr[pointer+j] = (value >> j) & 1;
        }

        if (code[i][0]==-1) break;
        pointer+=code_size;
        i++;
    }


    printf("\n\n nasza tablica big_arr:\n");
    show_array(big_arr, LEN*5);

    //save to 8bits
    i=0;
    pointer=0;
    int bytes_counter=0;
    while(1){
        double sum=0;
        for (int j=0; j<8; j++){
            if (big_arr[pointer+j]==1) {
                double two=2;
                double exp = (double) j;
                sum+=pow(two, exp);
            }

        }
        int sum2=(int) sum;
        value_into_array(arr, array_size, sum2);
        bytes_counter++;
        //poprawa - to caly if
        if (bytes_counter==255){
            for (int k=0; k<array_size; k++){
                if (arr[k]==-3) arr[k]=bytes_counter;
            }
            value_into_array(arr, array_size, -3);
            bytes_counter=0;
        }
        pointer+=8;
        i++;
        if (big_arr[pointer]==-1) break;
    }

    for (int k=0; k<array_size; k++){
        if (arr[k]==-3) arr[k]=bytes_counter;
    }

    //info that this is the end
    value_into_array(arr, array_size, 0);
    value_into_array(arr, array_size, 59);

    FILE *fp;
    int c;
    fp = fopen("D:\gif.gif", "rb"); // read mode
    while(1) {
        c = fgetc(fp);
        if( feof(fp) ) break;
        printf ("%d",c);
        printf(" ");
    }
    fclose(fp);
    printf("\n");

    //insert into file
    FILE *fp2;
    fp2 = fopen("D:\moj-gif6.gif","wb+");
    for (int i=0; i<array_size; i++){
        if(arr[i]==-1) break;
        c=arr[i];
        if(c!=13) fputc(c, fp2);
    }

    fclose(fp2);

    printf("\n\n");
    FILE *fp3;
    fp3 = fopen("D:\moj-gif6.gif", "rb"); // read mode
    while(1) {
        c = fgetc(fp3);
        if( feof(fp3) ) break;
        //if(c!=13) printf("0");
        printf ("%d",c);
        printf(" ");
    }
    fclose(fp3);

    printf("\n\nnasza array do zapisania: \n");
    show_array(arr, array_size);

    return(0);
}