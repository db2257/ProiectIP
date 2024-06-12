#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <fstream>
#include <graphics.h>
#include <cstdlib>
#include <windows.h>
#include <stdio.h>
using namespace std;

#define nr_linii_max 12
#define nr_coloane_max 26

void Meniu();
void Setari();
void Selectare_mod();
void Incepe_joc();
void Dimensiuni();
void Inapoi();
void Salveaza_Joc();
void Save_Game();
void Play_again();
void Jeton_player_1();
void Jeton_player_2();
struct Joc
{
    int a[20][35];
    int jucator;
    int linii=5;
    int coloane=5;
    int tip_joc;
    int scor_1=0;
    int scor_2=0;
    int linie_actuala;
    int coloana_actuala;
    int jeton[3]= {0,3,4};
};
Joc Game;
void Ecran_nou()
{
    int l_max=1200;
    int h_max=640;
    setfillstyle(SOLID_FILL, COLOR(102,0,0));
    bar(80,80,l_max-79,h_max-79);
}
// DESEN FII
void Desen_1()
{
    int spatiu_orizontal, spatiu_vertical, x_centru, y_centru, poly[8];
    int l_max=1200;
    int h_max=640;
    spatiu_orizontal=(l_max-160-Game.coloane*40)/2;
    spatiu_vertical=(h_max-160-Game.linii*40)/2;
    x_centru=Game.coloana_actuala*40+80+spatiu_orizontal+20;
    y_centru=Game.linie_actuala*40+80+spatiu_vertical+20;
    setfillstyle(SOLID_FILL, BLUE);
    bar(x_centru-14,y_centru-14,x_centru+14,y_centru+14);
    setfillstyle(SOLID_FILL, WHITE);
    bar(x_centru-8,y_centru+4,x_centru-4,y_centru+14);
    bar(x_centru+4,y_centru-8,x_centru+8,y_centru+14);
    bar(x_centru-8,y_centru-8,x_centru+8,y_centru-4);
    setcolor(WHITE);
    setlinestyle(0,15,1);

    poly[0]=x_centru-6;
    poly[1]=y_centru+4;

    poly[2]=x_centru+13;
    poly[3]=y_centru-14;

    poly[4]=x_centru+14;
    poly[5]=y_centru-12;

    poly[6]=x_centru-4;
    poly[7]=y_centru+5;

    setfillstyle(SOLID_FILL, WHITE);
    fillpoly(4,poly);


}
// BRAD
void Desen_2()
{
    int spatiu_orizontal, spatiu_vertical, x_centru, y_centru,poly[20];
    int l_max=1200;
    int h_max=640;
    spatiu_orizontal=(l_max-160-Game.coloane*40)/2;
    spatiu_vertical=(h_max-160-Game.linii*40)/2;
    x_centru=Game.coloana_actuala*40+80+spatiu_orizontal+20;
    y_centru=Game.linie_actuala*40+80+spatiu_vertical+20;

    poly[0]=x_centru;
    poly[1]=y_centru-15;

    poly[2]=x_centru+10;
    poly[3]=y_centru-5;

    poly[4]=x_centru+5;
    poly[5]=y_centru-5;

    poly[6]=x_centru+15;
    poly[7]=y_centru+5;

    poly[8]=x_centru-15;
    poly[9]=y_centru+5;

    poly[10]=x_centru-5;
    poly[11]=y_centru-5;

    poly[12]=x_centru-10;
    poly[13]=y_centru-5;

    poly[14]=x_centru;
    poly[15]=y_centru-15;
    setlinestyle(0,15,1);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, GREEN);

    fillpoly(7,poly);

    poly[0]=x_centru-5;
    poly[1]=y_centru+5;

    poly[2]=x_centru+5;
    poly[3]=y_centru+5;

    poly[4]=x_centru+5;
    poly[5]=y_centru+15;

    poly[6]=x_centru-5;
    poly[7]=y_centru+15;

    poly[8]=x_centru-5;
    poly[9]=y_centru+5;

    setfillstyle(SOLID_FILL, COLOR(144,96,0));
    fillpoly(4,poly);

}
// INIMA
void Desen_3()
{
    int spatiu_orizontal, spatiu_vertical, x_centru, y_centru,poly[20];
    int l_max=1200;
    int h_max=640;
    spatiu_orizontal=(l_max-160-Game.coloane*40)/2;
    spatiu_vertical=(h_max-160-Game.linii*40)/2;
    x_centru=Game.coloana_actuala*40+80+spatiu_orizontal+20;
    y_centru=Game.linie_actuala*40+80+spatiu_vertical+20;

    poly[0]=x_centru-15;
    poly[1]=y_centru-10;

    poly[2]=x_centru-10;
    poly[3]=y_centru-15;

    poly[4]=x_centru-5;
    poly[5]=y_centru-15;

    poly[6]=x_centru;
    poly[7]=y_centru-10;

    poly[8]=x_centru+5;
    poly[9]=y_centru-15;

    poly[10]=x_centru+10;
    poly[11]=y_centru-15;

    poly[12]=x_centru+15;
    poly[13]=y_centru-10;

    poly[14]=x_centru+15;
    poly[15]=y_centru-5;

    poly[16]=x_centru;
    poly[17]=y_centru+15;

    poly[18]=x_centru-15;
    poly[19]=y_centru-5;

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, RED);
    setlinestyle(0,15,1);
    fillpoly(10,poly);

}
// STEA
void Desen_4()
{
    int spatiu_orizontal, spatiu_vertical, x_centru, y_centru,poly[20];
    int l_max=1200;
    int h_max=640;
    spatiu_orizontal=(l_max-160-Game.coloane*40)/2;
    spatiu_vertical=(h_max-160-Game.linii*40)/2;
    x_centru=Game.coloana_actuala*40+80+spatiu_orizontal+20;
    y_centru=Game.linie_actuala*40+80+spatiu_vertical+20;
    poly[0]=x_centru-15;
    poly[1]=y_centru-3;

    poly[2]=x_centru-4;
    poly[3]=y_centru-3;

    poly[4]=x_centru;
    poly[5]=y_centru-15;

    poly[6]=x_centru+3;
    poly[7]=y_centru-3;

    poly[8]=x_centru+15;
    poly[9]=y_centru-3;

    poly[10]=x_centru+7;
    poly[11]=y_centru+3;

    poly[12]=x_centru+10;
    poly[13]=y_centru+15;

    poly[14]=x_centru;
    poly[15]=y_centru+7;

    poly[16]=x_centru-10;
    poly[17]=y_centru+15;

    poly[18]=x_centru-7;
    poly[19]=y_centru+3;

    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(14);
    setlinestyle(0,2,1);
    fillpoly(10,poly);
    setcolor(15);
}
void Checkmark(int x,int y)
{
    int poly[8];
    x=x+10;
    y=y+20;

    poly[0]=x;
    poly[1]=y-10;

    poly[2]=x+20;
    poly[3]=y+10;

    poly[4]=x+80;
    poly[5]=y-10;

    poly[6]=x+20;
    poly[7]=y+20;
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    fillpoly(4,poly);
    setcolor(WHITE);
}
void Chenar()
{
    int l_max=1200;
    int h_max=640;
    setfillstyle(CLOSE_DOT_FILL, COLOR(102,0,0));
    bar(0,0,l_max,h_max);
    setlinestyle(0,2,3);
    line(10,10,1190,10);
    line(10,10,10,630);
    line(10,630,1190,630);
    line(1190,10,1190,630);
    setlinestyle(0,2,3);
}
void Desenare_jeton()
{
    switch (Game.jeton[Game.jucator])
    {
    case 1:
        Desen_1();
        break;
    case 2:
        Desen_2();
        break;
    case 3:
        Desen_3();
        break;
    case 4:
        Desen_4();
        break;
    }
}
void afisare()
{
    delay(100);
}
void Fundal_tabla()
{
    int spatiu_orizontal,spatiu_vertical;
    int l_max=1200;
    int h_max=640;
    spatiu_orizontal=((l_max-160)-Game.coloane*40)/2;
    spatiu_vertical=((h_max-160)-Game.linii*40)/2;
    setfillstyle(SOLID_FILL,0);
    bar (80+spatiu_orizontal,80+spatiu_vertical,l_max-spatiu_orizontal-80,h_max-spatiu_vertical-80);
}
void Inapoi_meniu()
{
    char text[10]="MENIU";
    setcolor(WHITE);
    setlinestyle(0,2,3);
    settextstyle(0,0,3);
    outtextxy(18,10,text);
    setlinestyle(0,2,3);
    rectangle(10,10,140,31);
}
void Desenare_tabla()
{
    int i,j,spatiu_orizontal,spatiu_vertical,aux=Game.jucator;
    int l_max=1200;
    int h_max=640;
    setlinestyle(0,2,1);
    Chenar();
    Inapoi_meniu();
    Ecran_nou();
    Fundal_tabla();
    Salveaza_Joc();
    Jeton_player_1();
    Jeton_player_2();
    for (i=0; i<Game.linii; i++)
        for (j=0; j<Game.coloane; j++)
        {
            if (Game.a[i][j]!=0)
            {
                Game.linie_actuala=i;
                Game.coloana_actuala=j;
                Game.jucator=Game.a[i][j];
                Desenare_jeton();
            }
        }
    Game.jucator=aux;
    setcolor(WHITE);
    spatiu_orizontal=(l_max-160-Game.coloane*40)/2;
    spatiu_vertical=(h_max-160-Game.linii*40)/2;
    for (i=80+spatiu_orizontal; i<=80+spatiu_orizontal+Game.coloane*40; i=i+40)
    {
        line(i,80+spatiu_vertical,i,80+spatiu_vertical+Game.linii*40);
    }
    for (i=80+spatiu_vertical; i<=80+spatiu_vertical+Game.linii*40; i=i+40)
    {
        line(80+spatiu_orizontal,i,80+spatiu_orizontal+Game.coloane*40,i);
    }
}
void afiseazaScor()
{
    int l_max=1200;
    char sirScor1[10], sirScor2[10];
    setcolor(WHITE);
    settextstyle(6,0,3);
    itoa(Game.scor_1,sirScor1,10);
    itoa(Game.scor_2,sirScor2,10);
    strcat(sirScor1,"-");
    strcat(sirScor1,sirScor2);
    outtextxy(l_max/2-20,50,sirScor1);
}
bool Verificare_cinci_in_linie(int i,int j)
{
    int contor=1,aux,mutari_in_linie=5;
    if (Game.a[i][j]==0)
        return false;
    //cazul 1: verificam orizontal
    aux=j-1;
    while (aux>=0 && Game.a[i][aux]==Game.a[i][j])
    {
        contor++;
        aux--;
    }
    aux=j+1;
    while (aux<Game.coloane && Game.a[i][aux]==Game.a[i][j])
    {
        contor++;
        aux++;
    }
    if (contor>=mutari_in_linie)
    {
        delay(1000);
        return true;
    }
    //cazul 2: verificam vertical
    contor=1;
    aux=i-1;
    while (aux>=0 && Game.a[aux][j]==Game.a[i][j])
    {
        contor++;
        aux--;
    }
    aux=i+1;
    while (aux<Game.linii && Game.a[aux][j]==Game.a[i][j])
    {
        contor++;
        aux++;
    }
    if (contor>=mutari_in_linie)
    {
        delay(1000);
        return true;
    }
    //cazul 3: diagonala 1
    contor=1;
    aux=1;
    while (i-aux>=0 && j-aux>=0 && Game.a[i-aux][j-aux]==Game.a[i][j])
    {
        contor++;
        aux++;
    }
    aux=1;
    while (i+aux<Game.linii && j+aux<Game.coloane && Game.a[i+aux][j+aux]==Game.a[i][j])
    {
        contor++;
        aux++;
    }
    if (contor>=mutari_in_linie)
    {
        delay(1000);
        return true;
    }
    //cazul 4: diagonala 2
    contor=1;
    aux=1;
    while (i-aux>=0 && j+aux<Game.coloane &&Game.a[i-aux][j+aux]==Game.a[i][j])
    {
        contor++;
        aux++;
    }
    aux=1;
    while (i+aux<Game.linii && j-aux>=0 && Game.a[i+aux][j-aux]==Game.a[i][j])
    {
        contor++;
        aux++;
    }
    if (contor>=mutari_in_linie)
    {
        delay(1000);
        return true;
    }
    return false;
}
void Marcheaza_mutare_castigatoare(int i,int j)
{
    int l_max=1200;
    int h_max=640;
    int i_min,i_max,j_min,j_max,spatiu_orizontal, spatiu_vertical;
    int contor=1,aux,mutari_in_linie=5;
    i_min=i;
    i_max=i;
    j_min=j;
    j_max=j;
    spatiu_orizontal=80+(l_max-160-Game.coloane*40)/2;
    spatiu_vertical=80+(h_max-160-Game.linii*40)/2;
    aux=j-1;
    if (Game.a[i][j]==0)
        return;
    //cazul 1: verificam orizontal 1
    while (aux>=0 && Game.a[i][aux]==Game.a[i][j])
    {
        contor++;
        aux--;
    }
    aux++;
    if(aux<j_min)
    {
        j_min=aux;
    }
    aux=j+1;
    while (aux<Game.coloane && Game.a[i][aux]==Game.a[i][j])
    {
        contor++;
        aux++;
    }
    aux--;
    if(aux>j_max)
    {
        j_max=aux;
    }
    if (contor>=mutari_in_linie)
    {
        setfillstyle(SOLID_FILL,WHITE);
        bar(spatiu_orizontal+40*j_min,spatiu_vertical+40*i_min+18,spatiu_orizontal+40*(j_max+1),spatiu_vertical+40*i_min+20);
        delay(1000);
        return;
    }
    //cazul 2: verificam vertical
    contor=1;
    aux=i-1;
    while (aux>=0 && Game.a[aux][j]==Game.a[i][j])
    {
        contor++;
        aux--;
    }
    aux++;
    if(aux<i_min)
    {
        i_min=aux;
    }
    aux=i+1;
    while (aux<Game.linii && Game.a[aux][j]==Game.a[i][j])
    {
        contor++;
        aux++;
    }
    aux--;
    if(aux>i_max)
    {
        i_max=aux;
    }
    if (contor>=mutari_in_linie)
    {
        setfillstyle(SOLID_FILL,WHITE);
        bar(spatiu_orizontal+40*j_min+18,spatiu_vertical+40*i_min,spatiu_orizontal+40*j_min+21,spatiu_vertical+40*(i_max+1));
        delay(1000);
        return;
    }
    //cazul 3: diagonala 1
    contor=1;
    aux=1;
    while (i-aux>=0 && j-aux>=0 && Game.a[i-aux][j-aux]==Game.a[i][j])
    {
        contor++;
        aux++;
    }
    aux--;
    if(i-aux<i_min)
    {
        i_min=i-aux;
    }
    if(j-aux<j_min)
    {
        j_min=j-aux;
    }
    aux=1;
    while (i+aux<Game.linii && j+aux<Game.coloane && Game.a[i+aux][j+aux]==Game.a[i][j])
    {
        contor++;
        aux++;
    }
    aux--;
    if(i+aux>i_max)
    {
        i_max=i+aux;
    }
    if(j+aux>j_max)
    {
        j_max=j+aux;
    }
    if (contor>=mutari_in_linie)
    {
        setlinestyle(0,2,3);
        line(spatiu_orizontal+40*j_min,spatiu_vertical+40*i_min,spatiu_orizontal+40*(j_max+1),spatiu_vertical+40*(i_max+1));
        setlinestyle(0,2,1);
        delay(1000);
        return;
    }
    //cazul 4: diagonala 2
    contor=1;
    aux=1;
    while (i-aux>=0 && j+aux<Game.coloane &&Game.a[i-aux][j+aux]==Game.a[i][j])
    {
        contor++;
        aux++;
    }
    aux--;
    if(i-aux<i_min)
    {
        i_min=i-aux;
    }
    if(j+aux>j_max)
    {
        j_max=j+aux;
    }
    aux=1;
    while (i+aux<Game.linii && j-aux>=0 && Game.a[i+aux][j-aux]==Game.a[i][j])
    {
        contor++;
        aux++;
    }
    aux--;
    if(i+aux>i_max)
    {
        i_max=i+aux;
    }
    if(j-aux<j_min)
    {
        j_min=j-aux;
    }
    if (contor>=mutari_in_linie)
    {
        setlinestyle(0,2,3);
        line(spatiu_orizontal+40*(j_max+1),spatiu_vertical+40*i_min,spatiu_orizontal+40*j_min,spatiu_vertical+40*(i_max+1));
        setlinestyle(0,2,1);
        delay(1000);
        return;
    }
}
int Jucator_castigator()
{

    int i,j;
    for (i=0; i<Game.linii; i++)
        for (j=0; j<Game.coloane; j++)
            if (Verificare_cinci_in_linie(i,j))
            {
                return Game.a[i][j];
            }
    return 0;
}
void Cantec_castigator()
{
    Beep(235,305);

    Beep(310,305);

    Beep(310,300);

    Beep(385,300);

    Beep(510,300);

    Beep(385,300);

    Beep(455,805);
}
void Cantec_egalitate()
{
    Beep(560,300);

    Beep(560,300);

    Beep(560,300);

    Beep(500,300);

    Beep(445,300);

    Beep(500,300);

    Beep(385,800);
}
void Cantec_pierzator()
{
    Beep(445,300);

    Beep(499,300);

    Beep(375,1100);

    Beep(335,300);

    Beep(299,1000);
}
void Afisare_castigator()
{
    char text_1[30]="Castigator este Jucatorul ",text_jucator[10];
    char text_2[30]="Castigator este Calculatorul";
    char text_3[18]=" Joaca din nou ";
    int l_max=1200;
    int h_max=640;
    switch(Game.jucator)
    {
    case 1:
    {
        Ecran_nou();
        itoa(Game.jucator,text_jucator,10);
        strcat(text_1,text_jucator);
        setcolor(WHITE);
        settextstyle(10,0,5);
        outtextxy(l_max/4-60,h_max/2-60,text_1);
        setlinestyle(0,2,3);
        Cantec_castigator();
        Game.scor_1++;
        break;
    }
    case 2:
    {
        if (Game.tip_joc==1)
        {
            Ecran_nou();
            itoa(Game.jucator,text_jucator,10);
            strcat(text_1,text_jucator);
            setcolor(WHITE);
            settextstyle(10,0,5);
            outtextxy(l_max/4-60,h_max/2-60,text_1);
            Cantec_castigator();
        }
        else
        {
            Ecran_nou();
            setcolor(WHITE);
            settextstyle(10,0,5);
            outtextxy(l_max/4-60,h_max/2-60,text_2);
            Cantec_pierzator();
        }
        Game.scor_2++;
    }
    }
    afiseazaScor();
    Game.jucator=3-Game.jucator;
    settextstyle(10,0,5);
    outtextxy(l_max/2-187,h_max/3+150,text_3);
    setlinestyle(0,2,3);
    rectangle(410,362,788,403);
    clearmouseclick(WM_LBUTTONDOWN);
    int x,y;
    while(1)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if (y>=10 && y<=31 && x>=10 && x<=155)
            {
                Meniu();
                break;
            }
            if(x>=410 && x<=788 && y>=362 && y<=403)
            {
                Play_again();
                break;
            }
        }
    }
}
void Afisare_Egalitate()
{
    int l_max=1200;
    int h_max=640;
    Ecran_nou();
    char text_1[15]="Egalitate!";
    char text_2[18]=" Joaca din nou ";
    setcolor(WHITE);
    settextstyle(10,0,5);
    outtextxy(l_max/2-120,h_max/3+50,text_1);
    outtextxy(l_max/2-187,h_max/3+150,text_2);
    setlinestyle(0,2,3);
    rectangle(412,362,789,404);
    clearmouseclick(WM_LBUTTONDOWN);
    Cantec_egalitate();
    int x,y;
    while(1)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if (y>=10 && y<=31 && x>=10 && x<=155)
            {
                Meniu();
                break;
            }
            if(x>=412 && x<=789 && y>=362 && y<=404)
            {
                Play_again();
                break;
            }
        }
    }
}
bool Este_egalitate()
{
    int i,j;
    for (i=0; i<Game.linii; i++)
        for (j=0; j<Game.coloane; j++)
            if (Game.a[i][j]==0)
                return false;
    return true;
}
void Resetare_Joc()
{
    int i,j;
    for (i=0; i<Game.linii; i++)
        for (j=0; j<Game.coloane; j++)
            Game.a[i][j]=0;
    Game.scor_1=0;
    Game.scor_2=0;
    Game.jucator=1;
}
void Mutare_jucator()
{
    int coord_x,coord_y,spatiu_orizontal,spatiu_vertical;
    int l_max=1200;
    int h_max=640;
    spatiu_orizontal=(l_max-160-Game.coloane*40)/2;
    spatiu_vertical=(h_max-160-Game.linii*40)/2;
    bool done;
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        done=false;
        while (!done)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            coord_x=mousex();
            coord_y=mousey();
            if (coord_y>=10 && coord_y<=31 && coord_x>=10 && coord_x<=155)
            {
                Meniu();
                done=true;
                break;
            }
            if (coord_y>=10 && coord_y<=31 && coord_x>=895 && coord_x<=1190)
            {
                Save_Game();
            }
             //verificam daca se afla in interiorul tablei
            if ((coord_x>80+spatiu_orizontal && coord_x<l_max-80-spatiu_orizontal) && (coord_y>80+spatiu_vertical && coord_y<h_max-80-spatiu_vertical))
            {
                //calculam linia si coloana
                Game.coloana_actuala=(coord_x-80-spatiu_orizontal)/40;
                Game.linie_actuala=(coord_y-80-spatiu_vertical)/40;
                // daca casuta este goala, o completam
                if (Game.a[Game.linie_actuala][Game.coloana_actuala]==0)
                {
                    Game.a[Game.linie_actuala][Game.coloana_actuala]=Game.jucator;
                    Desenare_jeton();
                    if (Game.jucator==1)
                        Beep(600,200);
                    else
                        Beep(400,200);
                    done=true;
                    Game.jucator=3-Game.jucator;
                }
                else
                    break;
            }
            else
                break;
        }
    }
}
void Mutare_computer_easy()
{
    if (Game.jucator==2)
    {
        int i=0,j=0;
        bool done=false;
        while (!done)
        {
            i=rand() % Game.linii;
            j=rand() % Game.coloane;
            if (Game.a[i][j]==0)
            {
                Game.a[i][j]=2;
                Game.linie_actuala=i;
                Game.coloana_actuala=j;
                done=true;
                Game.jucator=2;
                Beep(300,200);
                Desenare_jeton();
                Game.jucator=1;
            }
        }
    }
}
void PvC_easy()
{
    Game.tip_joc=2;
    Desenare_tabla();
    bool done;
    Inapoi_meniu();
    done=false;
    do
    {
        if (Game.jucator==1)
            Mutare_jucator();
        else if (Game.jucator==2)
        {
            Mutare_computer_easy();
        }
        if (Jucator_castigator()!=0)
        {
            Marcheaza_mutare_castigatoare(Game.linie_actuala,Game.coloana_actuala);
            Game.jucator=3-Game.jucator;
            Afisare_castigator();
            done=true;
        }
        else if (Este_egalitate())
        {
            Afisare_Egalitate();
            done=true;
        }
        afiseazaScor();
        afisare();
    }
    while (!done);
}
void Mutare_computer_medium(int linie, int coloana)
{
    if (Game.jucator==2)
    {
        bool done=false;
        while(!done)
        {
            int j=coloana, i=linie;
            int contor=1,aux,mutari_in_linie=3;
            if(Game.a[i][j])
            {
                aux=j-1;
                while (aux>=0 && Game.a[i][aux]==Game.a[i][j])
                {
                    contor++;
                    aux--;
                }
                if (contor>=mutari_in_linie && aux>=0 && Game.a[i][aux]==0)
                {
                    Game.a[i][aux]=2;
                    Game.linie_actuala=i;
                    Game.coloana_actuala=aux;
                    done=true;
                    Game.jucator=2;
                    Desenare_jeton();
                    Beep(300,200);
                    Game.jucator=1;
                    break;
                }
                aux=j+1;
                while (aux<Game.coloane && Game.a[i][aux]==Game.a[i][j])
                {
                    contor++;
                    aux++;
                }
                if (contor>=mutari_in_linie && aux<Game.coloane && Game.a[i][aux]==0)
                {
                    Game.a[i][aux]=2;
                    Game.linie_actuala=i;
                    Game.coloana_actuala=aux;
                    done=true;
                    Game.jucator=2;
                    Desenare_jeton();
                    Beep(300,200);
                    Game.jucator=1;
                    break;
                }
                //cazul 2: verificam vertical
                contor=1;
                aux=i-1;
                while (aux>=0 && Game.a[aux][j]==Game.a[i][j])
                {
                    contor++;
                    aux--;
                }
                if (contor>=mutari_in_linie && aux>=0 && Game.a[aux][j]==0)
                {
                    Game.a[aux][j]=2;
                    Game.linie_actuala=aux;
                    Game.coloana_actuala=j;
                    done=true;
                    Game.jucator=2;
                    Desenare_jeton();
                    Beep(300,200);
                    Game.jucator=1;
                    break;
                }
                aux=i+1;
                while (aux<Game.linii && Game.a[aux][j]==Game.a[i][j])
                {
                    contor++;
                    aux++;
                }
                if (contor>=mutari_in_linie && aux<Game.linii && Game.a[aux][j]==0)
                {
                    Game.a[aux][j]=2;
                    Game.linie_actuala=aux;
                    Game.coloana_actuala=j;
                    done=true;
                    Game.jucator=2;
                    Desenare_jeton();
                    Beep(300,200);
                    Game.jucator=1;
                    break;
                }
                //cazul 3: diagonala 1
                contor=1;
                aux=1;
                while (i-aux>=0 && j-aux>=0 && Game.a[i-aux][j-aux]==Game.a[i][j])
                {
                    contor++;
                    aux++;
                }
                if (contor>=mutari_in_linie && i-aux>=0 && j-aux>=0 && Game.a[i-aux][j-aux]==0)
                {
                    Game.a[i-aux][j-aux]=2;
                    Game.linie_actuala=i-aux;
                    Game.coloana_actuala=j-aux;
                    done=true;
                    Game.jucator=2;
                    Desenare_jeton();
                    Beep(300,200);
                    Game.jucator=1;
                    break;
                }
                aux=1;
                while (i+aux<Game.linii && j+aux<Game.coloane && Game.a[i+aux][j+aux]==Game.a[i][j])
                {
                    contor++;
                    aux++;
                }
                if (contor>=mutari_in_linie && i+aux<Game.linii && j+aux<Game.coloane && Game.a[i+aux][j+aux]==0)
                {
                    Game.a[i+aux][j+aux]=2;
                    Game.linie_actuala=i+aux;
                    Game.coloana_actuala=j+aux;
                    done=true;
                    Game.jucator=2;
                    Desenare_jeton();
                    Beep(300,200);
                    Game.jucator=1;
                    break;
                }
                //cazul 4: diagonala 2
                contor=1;
                aux=1;
                while (i-aux>=0 && j+aux<Game.coloane &&Game.a[i-aux][j+aux]==Game.a[i][j])
                {
                    contor++;
                    aux++;
                }
                if (contor>=mutari_in_linie && i-aux>=0 && j+aux<Game.coloane && Game.a[i-aux][j+aux]==0)
                {
                    Game.a[i-aux][j+aux]=2;
                    Game.linie_actuala=i-aux;
                    Game.coloana_actuala=j+aux;
                    done=true;
                    Game.jucator=2;
                    Desenare_jeton();
                    Beep(300,200);
                    Game.jucator=1;
                    break;
                }
                aux=1;
                while (i+aux<Game.linii && j-aux>=0 && Game.a[i+aux][j-aux]==Game.a[i][j])
                {
                    contor++;
                    aux++;
                }
                if (contor>=mutari_in_linie && i+aux<Game.linii && j-aux>=0 && Game.a[i+aux][j-aux]==0)
                {
                    Game.a[i+aux][j-aux]=2;
                    Game.linie_actuala=i+aux;
                    Game.coloana_actuala=j-aux;
                    done=true;
                    Game.jucator=2;
                    Desenare_jeton();
                    Beep(300,200);
                    Game.jucator=1;
                    break;
                }
            }
            if(!done)
            {
                Mutare_computer_easy();
                done=true;
            }
        }
    }
}
void PvC_medium()
{
    Game.tip_joc=3;
    Desenare_tabla();
    bool done;
    done=false;
    do
    {
        if (Game.jucator==1)
        {
            Mutare_jucator();
        }
        else if (Game.jucator==2)
        {
            Mutare_computer_medium(Game.linie_actuala, Game.coloana_actuala);
        }
        if (Jucator_castigator()!=0)
        {
            Marcheaza_mutare_castigatoare(Game.linie_actuala,Game.coloana_actuala);
            Game.jucator=3-Game.jucator;
            Afisare_castigator();
            done=true;
        }
        else if (Este_egalitate())
        {
            Afisare_Egalitate();
            done=true;
        }
        afiseazaScor();
        afisare();
    }
    while (!done);
}
void Mutare_computer_hard(int linie, int coloana)
{
    if (Game.jucator==2)
    {
        bool done=false;
        int i,j;
        for (i=0; i<Game.linii && done==false; i++)
            for (j=0; j<Game.coloane && done==false; j++)
            {
                if (Game.a[i][j]==0)
                {
                    Game.a[i][j]=2;
                    if (Verificare_cinci_in_linie(i,j))
                    {
                        done=true;
                        Game.linie_actuala=i;
                        Game.coloana_actuala=j;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                    }
                    else
                        Game.a[i][j]=0;
                }
            }
        while(!done)
        {
            j=coloana;
            i=linie;
            int contor=1,aux,mutari_in_linie=2;
            if(Game.a[i][j])
            {
                // cazul 1: verificam orizontal
                aux=j-1;
                while (aux>=0 && Game.a[i][aux]==Game.a[i][j])
                {
                    contor++;
                    aux--;
                }
                if (contor>=mutari_in_linie && aux>=0 && Game.a[i][aux]==0)
                {
                    Game.linie_actuala=i;
                    Game.coloana_actuala=aux;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                if(contor>=mutari_in_linie && Game.a[i][j+1]==0)
                {
                    Game.linie_actuala=i;
                    Game.coloana_actuala=j+1;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                aux=j+1;
                while (aux<Game.coloane && Game.a[i][aux]==Game.a[i][j])
                {
                    contor++;
                    aux++;
                }
                if (contor>=mutari_in_linie && aux<Game.coloane && Game.a[i][aux]==0)
                {
                    Game.linie_actuala=i;
                    Game.coloana_actuala=aux;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                if(contor>=mutari_in_linie && Game.a[i][j-1]==0)
                {
                    Game.linie_actuala=i;
                    Game.coloana_actuala=j-1;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                //cazul 2: verificam vertical
                contor=1;
                aux=i-1;
                while (aux>=0 && Game.a[aux][j]==Game.a[i][j])
                {
                    contor++;
                    aux--;
                }
                if (contor>=mutari_in_linie && aux>=0 && Game.a[aux][j]==0)
                {
                    Game.linie_actuala=aux;
                    Game.coloana_actuala=j;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                if(contor>=mutari_in_linie && Game.a[i+1][j]==0)
                {
                    Game.linie_actuala=i+1;
                    Game.coloana_actuala=j;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                aux=i+1;
                while (aux<Game.linii && Game.a[aux][j]==Game.a[i][j])
                {
                    contor++;
                    aux++;
                }
                if (contor>=mutari_in_linie && aux<Game.linii && Game.a[aux][j]==0)
                {
                    Game.linie_actuala=aux;
                    Game.coloana_actuala=j;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                if(contor>=mutari_in_linie && Game.a[i-1][j]==0)
                {
                    Game.linie_actuala=i-1;
                    Game.coloana_actuala=j;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                //cazul 3: diagonala 1
                contor=1;
                aux=1;
                while (i-aux>=0 && j-aux>=0 && Game.a[i-aux][j-aux]==Game.a[i][j])
                {
                    contor++;
                    aux++;
                }
                if (contor>=mutari_in_linie && i-aux>=0 && j-aux>=0 && Game.a[i-aux][j-aux]==0)
                {
                    Game.linie_actuala=i-aux;
                    Game.coloana_actuala=j-aux;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                if(contor>=mutari_in_linie && Game.a[i+1][j+1]==0)
                {
                    Game.linie_actuala=i+1;
                    Game.coloana_actuala=j+1;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                aux=1;
                while (i+aux<Game.linii && j+aux<Game.coloane && Game.a[i+aux][j+aux]==Game.a[i][j])
                {
                    contor++;
                    aux++;
                }
                if (contor>=mutari_in_linie && i+aux<Game.linii && j+aux<Game.coloane && Game.a[i+aux][j+aux]==0)
                {
                    Game.linie_actuala=i+aux;
                    Game.coloana_actuala=j+aux;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                if(contor>=mutari_in_linie && Game.a[i-1][j-1]==0)
                {
                    Game.linie_actuala=i-1;
                    Game.coloana_actuala=j-1;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                //cazul 4: diagonala 2
                contor=1;
                aux=1;
                while (i-aux>=0 && j+aux<Game.coloane &&Game.a[i-aux][j+aux]==Game.a[i][j])
                {
                    contor++;
                    aux++;
                }
                if (contor>=mutari_in_linie && i-aux>=0 && j+aux<Game.coloane && Game.a[i-aux][j+aux]==0)
                {
                    Game.linie_actuala=i-aux;
                    Game.coloana_actuala=j+aux;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                if(contor>=mutari_in_linie && Game.a[i+1][j-1]==0)
                {
                    Game.linie_actuala=i+1;
                    Game.coloana_actuala=j-1;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                aux=1;
                while (i+aux<Game.linii && j-aux>=0 && Game.a[i+aux][j-aux]==Game.a[i][j])
                {
                    contor++;
                    aux++;
                }
                if (contor>=mutari_in_linie && i+aux<Game.linii && j-aux>=0 && Game.a[i+aux][j-aux]==0)
                {
                    Game.linie_actuala=i+aux;
                    Game.coloana_actuala=j-aux;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
                if(contor>=mutari_in_linie && Game.a[i-1][j+1]==0)
                {
                    Game.linie_actuala=i-1;
                    Game.coloana_actuala=j+1;
                    if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                    {
                        Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                        done=true;
                        Game.jucator=2;
                        Desenare_jeton();
                        Beep(300,200);
                        Game.jucator=1;
                        break;
                    }
                }
            }
            if(!done)
            {
                int l=0,c=0;
                for(l=0; l<Game.linii && !done; l++)
                    for(c=0; c<Game.coloane && !done; c++)
                    {
                        if(Game.a[l][c]==2)
                        {
                            if(Game.a[l][c-1]==0 && c-1>=0)
                            {
                                Game.linie_actuala=l;
                                Game.coloana_actuala=c-1;
                                if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                                {
                                    Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                                    Desenare_jeton();
                                    Beep(300,200);
                                    done=true;
                                    Game.jucator=1;
                                    break;
                                }
                            }
                            if(Game.a[l-1][c-1]==0 && l-1>=0 && c-1>=0)
                            {
                                Game.linie_actuala=l-1;
                                Game.coloana_actuala=c-1;
                                if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                                {
                                    Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                                    Desenare_jeton();
                                    Beep(300,200);
                                    done=true;
                                    Game.jucator=1;
                                    break;
                                }
                            }
                            if(Game.a[l-1][c]==0 && l-1>=0)
                            {
                                Game.linie_actuala=l-1;
                                Game.coloana_actuala=c;
                                if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                                {
                                    Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                                    Desenare_jeton();
                                    Beep(300,200);
                                    done=true;
                                    Game.jucator=1;
                                    break;
                                }
                            }
                            if(Game.a[l-1][c+1]==0 && l-1>=0 && c+1<Game.coloane)
                            {
                                Game.linie_actuala=l-1;
                                Game.coloana_actuala=c+1;
                                if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                                {
                                    Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                                    Desenare_jeton();
                                    Beep(300,200);
                                    done=true;
                                    Game.jucator=1;
                                    break;
                                }
                            }
                            if(Game.a[l][c+1]==0 && c+1<Game.coloane)
                            {
                                Game.linie_actuala=l;
                                Game.coloana_actuala=c+1;
                                if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                                {
                                    Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                                    Desenare_jeton();
                                    Beep(300,200);
                                    done=true;
                                    Game.jucator=1;
                                    break;
                                }
                            }
                            if(Game.a[l+1][c+1]==0 && l+1<Game.linii && c+1<Game.coloane)
                            {
                                Game.linie_actuala=l+1;
                                Game.coloana_actuala=c+1;
                                if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                                {
                                    Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                                    Desenare_jeton();
                                    Beep(300,200);
                                    done=true;
                                    Game.jucator=1;
                                    break;
                                }
                            }
                            if(Game.a[l+1][c]==0 && l+1<Game.linii)
                            {
                                Game.linie_actuala=l+1;
                                Game.coloana_actuala=c;
                                if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                                {
                                    Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                                    Desenare_jeton();
                                    Beep(300,200);
                                    done=true;
                                    Game.jucator=1;
                                    break;
                                }
                            }
                            if(Game.a[l+1][c-1]==0 && l+1<Game.linii && c-1>=0)
                            {
                                Game.linie_actuala=l+1;
                                Game.coloana_actuala=c-1;
                                if (Game.linie_actuala>=0 && Game.linie_actuala<Game.linii && Game.coloana_actuala>=0 && Game.coloana_actuala<Game.coloane)
                                {
                                    Game.a[Game.linie_actuala][Game.coloana_actuala]=2;
                                    Desenare_jeton();
                                    Beep(300,200);
                                    done=true;
                                    Game.jucator=1;
                                    break;
                                }
                            }
                        }
                    }
            }
            if(!done)
            {
                Mutare_computer_easy();
                done=true;
                break;
            }
        }
    }
}
void PvC_hard()
{
    Game.tip_joc=4;
    Desenare_tabla();
    bool done;
    done=false;
    do
    {
        if (Game.jucator==1)
        {
            Mutare_jucator();
        }
        else if (Game.jucator==2)
        {
            Mutare_computer_hard(Game.linie_actuala, Game.coloana_actuala);
        }
        if (Jucator_castigator()!=0)
        {
            Marcheaza_mutare_castigatoare(Game.linie_actuala,Game.coloana_actuala);
            Game.jucator=3-Game.jucator;
            Afisare_castigator();
            done=true;
        }
        else if (Este_egalitate())
        {
            Afisare_Egalitate();
            done=true;
        }
        afiseazaScor();
        afisare();
    }
    while (!done);
}
void Cinci_in_linie_PvP()
{
    Game.tip_joc=1;
    Desenare_tabla();
    bool done;
    done=false;
    do
    {
        Mutare_jucator();
        if (Jucator_castigator()!=0)
        {
            Marcheaza_mutare_castigatoare(Game.linie_actuala,Game.coloana_actuala);
            delay(1000);
            Game.jucator=3-Game.jucator;
            Afisare_castigator();
            done=true;
        }
        else if (Este_egalitate())
        {
            Afisare_Egalitate();
            done=true;
        }
        afiseazaScor();
        afisare();
    }
    while (!done);
}
void Load_Game()
{
    FILE *fptr= fopen("fisier.txt","rb");
    int i,j,aux;
    fread(&Game.linii, sizeof(Game.linii), 1, fptr);
    fread(&Game.coloane, sizeof(Game.coloane), 1, fptr);
    fread(&Game.tip_joc, sizeof(Game.tip_joc), 1, fptr);
    fread(&Game.jucator, sizeof(Game.jucator), 1, fptr);
    fread(&Game.scor_1, sizeof(Game.scor_1), 1, fptr);
    fread(&Game.scor_2, sizeof(Game.scor_2), 1, fptr);
    Game.jeton[0]=0;
    fread(&Game.jeton[1], sizeof(Game.jeton[1]), 1, fptr);
    fread(&Game.jeton[2], sizeof(Game.jeton[2]), 1, fptr);
    for (i=0; i<Game.linii; i++)
        for (j=0; j<Game.coloane; j++)
        {
            fread(&Game.a[i][j], sizeof(short), 1, fptr);
            fread(&aux, sizeof(short), 1, fptr);
        }
    fclose(fptr);
    switch(Game.tip_joc)
    {
    case 1:
    {
        Cinci_in_linie_PvP();
        break;
    }
    case 2:
    {
        PvC_easy();
        break;
    }
    case 3:
    {
        PvC_medium();
        break;
    }
    case 4:
    {
        PvC_hard();
        break;
    }
    }
}
void Play_again()
{
    int i,j;
    for (i=0; i<Game.linii; i++)
        for (j=0; j<Game.coloane; j++)
            Game.a[i][j]=0;
    Game.jucator=1;
    switch(Game.tip_joc)
    {
    case 1:
    {
        Cinci_in_linie_PvP();
        break;
    }
    case 2:
    {
        PvC_easy();
        break;
    }
    case 3:
    {
        PvC_medium();
        break;
    }
    case 4:
    {
        PvC_hard();
        break;
    }
    }
}
void Save_Game()
{
    FILE *fptr= fopen("fisier.txt","wb");
    int i,j;
    fwrite(&Game.linii, sizeof(Game.linii), 1, fptr);
    fwrite(&Game.coloane,  sizeof(Game.coloane), 1, fptr);
    fwrite(&Game.tip_joc, sizeof(Game.tip_joc), 1, fptr);
    fwrite(&Game.jucator, sizeof(Game.jucator), 1, fptr);
    fwrite(&Game.scor_1, sizeof(Game.scor_1), 1, fptr);
    fwrite(&Game.scor_2, sizeof(Game.scor_2), 1, fptr);
    fwrite(&Game.jeton[1], sizeof(Game.jeton[1]), 1, fptr);
    fwrite(&Game.jeton[2], sizeof(Game.jeton[2]), 1, fptr);
    for (i=0; i<Game.linii; i++)
    {
        for (j=0; j<Game.coloane; j++)
        {
            fwrite(&Game.a[i][j], sizeof(Game.a[i][j]), 1, fptr);
        }
    }
    fclose(fptr);
}
void Salveaza_Joc()
{
    char text[20]="SALVEAZA JOC";
    setcolor(WHITE);
    settextstyle(0,0,3);
    outtextxy(900,10,text);
    setlinestyle(0,2,3);
    rectangle(895,10,1190,31);
    setlinestyle(0,2,1);
}
void Inapoi()
{
    char text[10]="INAPOI";
    setcolor(WHITE);
    setlinestyle(0,2,3);
    settextstyle(0,0,3);
    outtextxy(10,10,text);
    setlinestyle(0,2,3);
    rectangle(10,10,155,31);
}
void Iesire()
{
    char text[10]="IESIRE";
    setcolor(WHITE);
    setlinestyle(0,2,3);
    settextstyle(0,0,3);
    outtextxy(10,10,text);
    setlinestyle(0,2,3);
    rectangle(10,10,155,31);
}
void Reguli()
{
    Chenar();
    Inapoi();
    int inapoi=1,x,y;
    char text_1[150]="Acesta este un joc care se joaca in doi.";
    char text_2[100]="Jucatorii isi aseaza alternant piesele pe tabla de joc.";
    char text_3[150]="Castigator este primul jucator care obtine o formatie de ";
    char text_4[100]="cinci piese in linie pe verticala, orizontala sau pe diagonale.";
    char text_5[100]="Daca nu raman pozitii libere si nu exista castigator, jocul se incheie in egalitate.";
    settextstyle(6,0,2);
    setcolor(WHITE);
    outtextxy(400,140,text_1);
    outtextxy(310,210,text_2);
    outtextxy(270,280,text_3);
    outtextxy(250,350,text_4);
    outtextxy(120,420,text_5);
    while(inapoi)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                Meniu();
                inapoi=0;
            }
        }
    }
}
void Nivel_de_dificultate()
{
    Chenar();
    Inapoi();
    int l_max=1200;
    int h_max=640;
    int x,y,inapoi=1;
    char text[35]="Alegeti nivelul de dificultate:", text_1[20]=" USOR ", text_2[20]=" MEDIU ", text_3[20]=" GREU ";
    setcolor(WHITE);
    settextstyle(0,0,60);
    outtextxy(l_max/5-20,h_max/4+50,text);
    outtextxy(l_max/4-70,h_max/3+100,text_1);
    outtextxy(l_max/4+220,h_max/3+100,text_2);
    outtextxy(l_max/4+520,h_max/3+100,text_3);
    setlinestyle(0,2,3);
    rectangle(228,313,382,354);
    rectangle(520,313,696,354);
    rectangle(820,313,973,354);
    while(1)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if(x>=260 && x<=360 && y>=315 && y<=348)
            {
                Resetare_Joc();
                PvC_easy();
                break;
            }
            if(x>=550 && x<=672 && y>=315 && y<=348)
            {
                Resetare_Joc();
                PvC_medium();
                break;
            }
            if(x>=852 && x<=950 && y>=315 && y<=348)
            {
                Resetare_Joc();
                PvC_hard();
                break;
            }
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                Selectare_mod();
                inapoi=0;
            }
        }
    }
    while(inapoi)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                Selectare_mod();
                inapoi=0;
            }
        }
    }
}
void Selectare_mod()
{
    Chenar();
    Inapoi();
    int l_max=1200;
    int h_max=640;
    int x,y,inapoi=1;
    char text_1[25]=" Player VS Player ", text_2[25]=" Player VS Computer ";
    setcolor(WHITE);
    settextstyle(0,0,40);
    outtextxy(l_max/3-145,h_max/4+40,text_1);
    outtextxy(l_max/3-180,h_max/4+220,text_2);
    setlinestyle(0,2,3);
    rectangle(255,197,957,261);
    rectangle(218,377,1001,444);
    while(1)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if((x>l_max/3-115 && x<l_max/3+510) && (y>h_max/4+40 && y<h_max/4+105))
            {
                Resetare_Joc();
                closegraph(CURRENT_WINDOW);
                initwindow(l_max,h_max,"Cinci in linie");
                Cinci_in_linie_PvP();
                break;
            }
            if((x>l_max/3-150 && x<l_max/3+550) && (y>h_max/4+220 && y<h_max/4+285))
            {
                closegraph(CURRENT_WINDOW);
                initwindow(l_max,h_max,"Cinci in linie");
                Nivel_de_dificultate();
                break;
            }
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                Incepe_joc();
                inapoi=0;
            }
        }
    }
    while(inapoi)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                Incepe_joc();
                inapoi=0;
            }
        }
    }
}
void Incepe_joc()
{
    Chenar();
    Inapoi();
    int l_max=1200;
    int h_max=640;
    int x,y, inapoi=1;
    char text_1[20]=" CONTINUARE JOC ", text_2[15]=" JOC NOU ";
    setcolor(WHITE);
    settextstyle(0,0,40);
    outtextxy(l_max/3-100,h_max/4+70,text_1);
    outtextxy(l_max/3+35,h_max/3+150,text_2);
    setlinestyle(0,2,3);
    rectangle(301,228,923,293);
    rectangle(435,362,785,425);
    while(1)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if((x>l_max/3-70 && x<l_max/3+475) && (y>h_max/4+70 && y<h_max/4+135))
            {
                closegraph(CURRENT_WINDOW);
                initwindow(l_max,h_max,"Cinci in linie");
                Load_Game();
                break;
            }
            if((l_max/3+65 && x<785) && (y>h_max/3+150 && y<h_max/3+215))
            {
                closegraph(CURRENT_WINDOW);
                initwindow(l_max,h_max,"Cinci in linie");
                Selectare_mod();
                break;
            }
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                Meniu();
                inapoi=0;
            }
        }
    }
    while(inapoi)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                Meniu();
                inapoi=0;
            }
        }
    }
}
void Selectare_jeton()
{
    Chenar();
    Inapoi();
    int l_max=1200;
    int h_max=640;
    int x,y,j=0, player_1=1, player_2=1, inapoi,linii_aux, coloane_aux;
    char text_1[40]="SELECTATI JETONUL PENTRU PLAYER 1";
    char text_2[40]="SELECTATI JETONUL PENTRU PLAYER 2";
    setcolor(WHITE);
    settextstyle(0,0,60);
    outtextxy(l_max/6,h_max/5,text_1);
    outtextxy(l_max/6,h_max/2,text_2);
    linii_aux=Game.linii;
    coloane_aux=Game.coloane;
    Game.linii=12;
    Game.coloane=12;
    Game.linie_actuala=3;
    Game.coloana_actuala=j;
    Desen_1();
    j+=4;
    Game.coloana_actuala=j;
    Desen_2();
    j+=4;
    Game.coloana_actuala=j;
    Desen_3();
    j+=4;
    Game.coloana_actuala=j;
    j=0;
    Desen_4();
    Game.linie_actuala=8;
    Game.coloana_actuala=j;
    Desen_1();
    j+=4;
    Game.coloana_actuala=j;
    Desen_2();
    j+=4;
    Game.coloana_actuala=j;
    Desen_3();
    j+=4;
    Game.coloana_actuala=j;
    Desen_4();
    Game.linii=linii_aux;
    Game.coloane=coloane_aux;
    while(player_1 || player_2)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if(player_1)
            {
                if(y>=205 && y<=235)
                {
                    if(x>=367 && x<=392 && ((Game.jeton[2]!=1 && player_2==0) || player_2))
                    {
                        rectangle(360,200,400,240);
                        Game.jeton[1]=1;
                        player_1=0;
                        Checkmark(1030,h_max/5);
                    }
                    else if(x>=525 && x<=554 && ((Game.jeton[2]!=2 && player_2==0) || player_2))
                    {
                        rectangle(520,200,560,240);
                        Game.jeton[1]=2;
                        player_1=0;
                        Checkmark(1030,h_max/5);
                    }
                    else if(x>=682 && x<=716 && ((Game.jeton[2]!=3 && player_2==0) || player_2))
                    {
                        rectangle(680,200,720,240);
                        Game.jeton[1]=3;
                        player_1=0;
                        Checkmark(1030,h_max/5);
                    }
                    else if(x>=842 && x<=876 && ((Game.jeton[2]!=4 && player_2==0) || player_2))
                    {
                        rectangle(840,200,880,240);
                        Game.jeton[1]=4;
                        player_1=0;
                        Checkmark(1030,h_max/5);
                    }
                }
            }
            if(player_2)
            {
                if(y>=403 && y<=435)
                {
                    if(x>=367 && x<=392 && Game.jeton[1]!=1)
                    {
                        rectangle(360,400,400,440);
                        Game.jeton[2]=1;
                        player_2=0;
                        Checkmark(1030,h_max/2);
                    }
                    else if(x>=525 && x<=554 && Game.jeton[1]!=2)
                    {
                        rectangle(520,400,560,440);
                        Game.jeton[2]=2;
                        player_2=0;
                        Checkmark(1030,h_max/2);
                    }
                    else if(x>=682 && x<=716 && Game.jeton[1]!=3)
                    {
                        rectangle(680,400,720,440);
                        Game.jeton[2]=3;
                        player_2=0;
                        Checkmark(1030,h_max/2);
                    }
                    else if(x>=842 && x<=876 && Game.jeton[1]!=4)
                    {
                        rectangle(840,400,880,440);
                        Game.jeton[2]=4;
                        player_2=0;
                        Checkmark(1030,h_max/2);
                    }
                }
            }
            if(x>=10 && x<=155 && y>=10 && y<=31 && Game.jeton[1]!=Game.jeton[2] && player_1==player_2)
            {
                Setari();
                inapoi=0;
            }
        }
    }
    while(inapoi || Game.jeton[1]!=Game.jeton[2])
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                Setari();
                inapoi=0;
            }
        }
    }
}
void CitesteSir(int x, int y, char S[12])
{
    char Enter = 13, BackSpace = 8, Escape = 27, s2[2];
    s2[1]='\0';
    char MultimeDeCaractereAcceptabile[12]="0123456789";
    char S_initial[12], tasta, S_[12];
    strcpy(S_initial,S);
    strcpy(S,"");
    strcpy(S_,S);
    strcat(S_," ");
    setcolor(WHITE);
    settextstyle(0,0,3);
    outtextxy(x,y,S_);
    s2[0]=tasta;
    strcat(S,s2);
    strcpy(S_,S);
    strcat(S_," ");
    outtextxy(x,y,S_);
    do
    {
        tasta=getch();
        if (tasta==0)
        {
            tasta=getch();
        }
        else if (strchr(MultimeDeCaractereAcceptabile, tasta))
        {
            // stergem fostul sir
            strcpy(S_,S);
            strcat(S_," ");
            outtextxy(x,y,S_);
            s2[0]=tasta;
            strcat(S,s2);
            strcpy(S_,S);
            strcat(S_," ");
            outtextxy(x,y,S_);
        }
        if (tasta==BackSpace)
        {
            if ((strcmp(S,"")))
            {
                outtextxy(x,y,S_);
                S[strlen(S)-1]='\0';
                strcpy(S_,S);
                strcat(S_," ");
                outtextxy(x,y,S_);
            }
        }
    }
    while (tasta!=Enter && tasta!=Escape);
    outtextxy(x,y,S_);
    outtextxy(x,y,S);
    setlinestyle(0,2,3);
    rectangle(930,251,990,290);
    rectangle(960,351,1023,390);
}
void Dimensiune_speciala()
{
    Chenar();
    Inapoi();
    int x,y,inapoi=1,citeste_l=1,citeste_c=1,valoare;
    char text_1[100]="Introduceti dimensiunile dorite dupa care apasati tasta ENTER!";
    char text_2[50]="Introduceti numarul de linii:  ";
    char text_3[50]="Introduceti numarul de coloane:  ";
    char sir[12];
    setcolor(WHITE);
    settextstyle(0,0,80);
    outtextxy(105,130,text_1);
    settextstyle(0,0,60);
    outtextxy(210,250,text_2);
    outtextxy(190,350,text_3);
    setlinestyle(0,2,3);
    rectangle(930,251,990,290);
    rectangle(960,351,1023,390);

    while(citeste_l || citeste_c)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if((x>=930 && x<=986) && (y>=251 && y<=287))
            {
                CitesteSir(937,263,sir);
                valoare=atoi(sir);
                if (valoare<=12)
                {
                    Checkmark(1000,247);
                    Game.linii=valoare;
                    citeste_l=0;
                }
                else
                {
                    setfillstyle(SOLID_FILL,0);
                    bar(340,240,850,390);
                    setcolor(15);
                    rectangle(340,240,850,390);
                    char text_eroare[30]="Dimensiune incorecta";
                    char mesaj_eroare[100]="Numarul maxim de linii este 12";
                    char text_ok[10]="OK";
                    settextstyle(0,0,3);
                    outtextxy(356,270,text_eroare);
                    outtextxy(572,350,text_ok);
                    rectangle(568,348,626,372);
                    settextstyle(0,0,2);
                    outtextxy(390,312,mesaj_eroare);
                    while(1)
                    {
                        if (ismouseclick(WM_LBUTTONDOWN))
                        {
                          getmouseclick(WM_LBUTTONDOWN, x, y);
                          clearmouseclick(WM_LBUTTONDOWN);
                          if(x>=568 && x<=626 &&y>=348 &&y<=372)
                          {
                              Dimensiune_speciala();
                              break;
                          }
                        }
                    }
                }

            }
            if((x>=960 && x<=1017) && (y>=351 && y<=387))
            {
                CitesteSir(968,363,sir);
                valoare=atoi(sir);
                if (valoare<=26)
                {
                    Checkmark(1034,347);
                    Game.coloane=valoare;
                    citeste_c=0;
                }
                else
                {
                    setfillstyle(SOLID_FILL,0);
                    bar(340,240,850,390);
                    setcolor(15);
                    rectangle(340,240,850,390);
                    char text_eroare[30]="Dimensiune incorecta";
                    char mesaj_eroare[100]="Numarul maxim de coloane este 26";
                    char text_ok[10]="OK";
                    settextstyle(0,0,3);
                    outtextxy(356,270,text_eroare);
                    outtextxy(572,350,text_ok);
                    rectangle(568,348,626,372);
                    settextstyle(0,0,2);
                    outtextxy(370,312,mesaj_eroare);
                    while(1)
                    {
                        if (ismouseclick(WM_LBUTTONDOWN))
                        {
                          getmouseclick(WM_LBUTTONDOWN, x, y);
                          clearmouseclick(WM_LBUTTONDOWN);
                          if(x>=568 && x<=626 &&y>=348 &&y<=372)
                          {
                              Dimensiune_speciala();
                              break;
                          }
                        }
                    }

                }
            }
            if(x>=10 && x<=155 && y>=10 && y<=31 && citeste_l==citeste_c)
            {
                Dimensiuni();
                inapoi=0;
            }
        }
    }
    while(inapoi && citeste_l==citeste_c)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                Dimensiuni();
                inapoi=0;
            }
        }
    }
}
void Dimensiuni()
{
    Chenar();
    Inapoi();
    int x,y,inapoi=1;
    char text_1[20]=" 5x5-marime minima ";
    char text_2[20]=" 10x10 ";
    char text_3[25]=" 12x26-marime maxima ";
    char text_4[20]=" marime speciala ";
    setcolor(WHITE);
    settextstyle(0,0,50);
    outtextxy(250,120,text_1);
    outtextxy(470,220,text_2);
    outtextxy(210,320,text_3);
    outtextxy(290,420,text_4);
    setlinestyle(0,2,3);
    rectangle(250,120,935,170);
    rectangle(470,221,722,272);
    rectangle(210,320,967,372);
    rectangle(290,420,903,472);
    while(1)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if((x>250 && x<935) && (y>120 && y<170))
            {
                Game.linii=5;
                Game.coloane=5;
                Checkmark(940,120);
                break;
            }
            if((x>470 && x<722) && (y>220 && y<272))
            {
                Game.linii=10;
                Game.coloane=10;
                Checkmark(727,220);
                break;
            }
            if((x>210 && x<967) && (y>320 && y<372))
            {
                Game.linii=12;
                Game.coloane=26;
                Checkmark(972,320);
                break;
            }
            if((x>290 && x<903) && (y>420 && y<472))
            {
                Dimensiune_speciala();
                break;
            }
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                Setari();
                inapoi=0;
            }
        }
    }
    while(inapoi)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                Setari();
                inapoi=0;
            }
        }
    }
}
void Setari()
{
    Chenar();
    Inapoi();
    int l_max=1200;
    int h_max=640;
    int x,y,inapoi=1;
    char text_1[20]=" SELECTARE JETON ", text_2[20]=" DIMENSIUNE TABLA ";
    setcolor(WHITE);
    settextstyle(0,0,40);
    outtextxy(l_max/4-30,h_max/4+50,text_1);
    outtextxy(l_max/4-48,h_max/3+120,text_2);
    setlinestyle(0,2,3);
    rectangle(270,207,933,273);
    rectangle(252,332,954,396);
    while(1)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if((x>l_max/4 && x<l_max/4+590) && (y>h_max/4+50 && y<h_max/4+110))
            {
                Selectare_jeton();
                break;
            }
            if((x>l_max/4-18 && x<l_max/4+610) && (y>h_max/3+120 && y<h_max/3+185))
            {
                Dimensiuni();
                break;
            }
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                Meniu();
                inapoi=0;
            }
        }
    }
    while(inapoi)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                Meniu();
                inapoi=0;
            }
        }
    }
}
void Jeton_player_1()
{
    int linii_aux,coloane_aux;
    char text[10]="PLAYER 1:";
    setcolor(WHITE);
    settextstyle(0,0,2);
    outtextxy(115,55,text);
    linii_aux=Game.linii;
    coloane_aux=Game.coloane;
    Game.linii=12;
    Game.coloane=22;
    Game.linie_actuala=-1;
    Game.coloana_actuala=2;
    switch (Game.jeton[1])
    {
    case 1:
        Desen_1();
        break;
    case 2:
        Desen_2();
        break;
    case 3:
        Desen_3();
        break;
    case 4:
        Desen_4();
        break;
    }
    Game.linii=linii_aux;
    Game.coloane=coloane_aux;
}
void Jeton_player_2()
{
    int linii_aux,coloane_aux;
    char text[12]="";
    if (Game.tip_joc==1)
        strcpy(text,"PLAYER 2:");
    else
        strcpy(text,"COMPUTER:");
    setcolor(WHITE);
    settextstyle(0,0,2);
    outtextxy(910,55,text);
    linii_aux=Game.linii;
    coloane_aux=Game.coloane;
    Game.linii=12;
    Game.coloane=22;
    Game.linie_actuala=-1;
    Game.coloana_actuala=22;
    switch (Game.jeton[2])
    {
    case 1:
        Desen_1();
        break;
    case 2:
        Desen_2();
        break;
    case 3:
        Desen_3();
        break;
    case 4:
        Desen_4();
        break;
    }
    Game.linii=linii_aux;
    Game.coloane=coloane_aux;
}
void Meniu()
{
    Chenar();
    Iesire();
    int l_max=1200;
    int h_max=640;
    int x,y;
    char text_1[20]=" INCEPE JOC ", text_2[15]=" SETARI ", text_3[15]=" REGULI " ;
    setcolor(WHITE);
    settextstyle(0,0,40);
    outtextxy(l_max/3-30,h_max/4+20,text_1);
    outtextxy(l_max/3+45,h_max/3+70,text_2);
    outtextxy(l_max/3+45,h_max/2+70,text_3);
    setlinestyle(0,2,3);
    rectangle(369,178,838,244);
    rectangle(443,281,757,347);
    rectangle(445,388,755,451);
    while(1)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if(x>=10 && x<=155 && y>=10 && y<=31)
            {
                closegraph();
                ExitProcess(0);
                break;
            }
            else
            {
                if((x>l_max/3 && x<l_max/3+390) && (y>h_max/4+20 && y<h_max/4+85))
                {
                    closegraph(CURRENT_WINDOW);
                    initwindow(l_max,h_max,"Cinci in linie");
                    Incepe_joc();
                    break;
                }
                if((x>l_max/3+75 && x<l_max/3+310) && (y>h_max/3+70 && y<h_max/3+135))
                {
                    closegraph(CURRENT_WINDOW);
                    initwindow(l_max,h_max,"Cinci in linie");
                    Setari();
                    break;
                }
                if((x>l_max/3+75 && x<l_max/3+310) && (y>h_max/2+70 && y<h_max/2+135))
                {
                    closegraph(CURRENT_WINDOW);
                    initwindow(l_max,h_max,"Cinci in linie");
                    Reguli();
                    break;
                }
            }
        }
    }
}
void Ecran_principal()
{
    int l_max=1200;
    int h_max=640;
    int x,i,y;
    setfillstyle(CLOSE_DOT_FILL, COLOR(102,0,0));
    bar(0,0,l_max,h_max);
    Chenar();
    char text[20]=" CINCI IN LINIE ", text_2[15]=" START ";
    setcolor(WHITE);
    settextstyle(0,0,40);
    rectangle(290,210,922,280);
    outtextxy(295,213,text);
    settextstyle(0,0,38);
    outtextxy(l_max/3+110,h_max/2,text_2);
    setlinestyle(0,2,3);
    rectangle(510,318,686,361);
    for (i=0; i<=4; i++)
    {
        Game.linie_actuala=4+i;
        Game.coloana_actuala=9+i;
        Desen_1();
    }
    for (i=0; i<=4; i++)
    {
        Game.linie_actuala=7;
        Game.coloana_actuala=-10+i;
        Desen_2();
    }
    for (i=0; i<=4; i++)
    {
        Game.linie_actuala=0-i;
        Game.coloana_actuala=-9+i;
        Desen_3();
    }
    for (i=0; i<=4; i++)
    {
        Game.linie_actuala=-4+i;
        Game.coloana_actuala=12;
        Desen_4();
    }
    while(1)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if((x>l_max/3+138 && x<l_max/3+265) && (y>h_max/2-7 && y<h_max/2+42))
            {
                closegraph(CURRENT_WINDOW);
                initwindow(l_max,h_max,"Cinci in linie");
                Meniu();
                break;
            }
        }
    }
}
int main()
{
    int l_max=1200;
    int h_max=640;
    initwindow(l_max,h_max,"Cinci in linie");
    Ecran_principal();
    getch();
    closegraph();
    return 0;
}
