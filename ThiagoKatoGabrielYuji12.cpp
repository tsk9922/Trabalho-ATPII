#include <stdio.h>
#include <conio2.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

///_________________________________________________________
//STRUCTURES
//¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
struct tJogo
{
	int cod;
	char desc[50];
	char status;
};

struct tPart
{
	int cod;
	char desc[50];
	char status;
};

struct tCamp
{
	int codC;
	char titulo[50];
	char responsavel[50];
	int ano;
	int codJ;
	char desc[200];
	char status;
};

struct tJogador
{
	int codC;
	int codP;
	char nick[50];
	char status;
};

///_________________________________________________________
//FUNCTIONS
//¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
void fInicializar(void)
{
	FILE *pJogo = fopen("aJogo.dat", "wb");
	FILE *pPart	= fopen("aPart.dat", "wb");
	FILE *pCamp	= fopen("aCamp.dat", "wb");
	FILE *pJogador = fopen("aJogador.dat", "wb");
	
	tJogo Jogo;
	tPart Participante;
	tCamp Campeonato;
	tJogador Jogador;
	
	
	//JOGOS========================================================
	Jogo.cod = 1;
	strcpy(Jogo.desc, "League of Legends");
	Jogo.status = 'A';
	fwrite(&Jogo, sizeof(tJogo), 1, pJogo);
	
	Jogo.cod = 2;
	strcpy(Jogo.desc, "Fortnite");
	Jogo.status = 'A';
	fwrite(&Jogo, sizeof(tJogo), 1, pJogo);
	
	Jogo.cod = 3;
	strcpy(Jogo.desc, "Mortal Kombat");
	Jogo.status = 'A';
	fwrite(&Jogo, sizeof(tJogo), 1, pJogo);
	
	Jogo.cod = 4;
	strcpy(Jogo.desc, "CS:GO");
	Jogo.status = 'A';
	fwrite(&Jogo, sizeof(tJogo), 1, pJogo);
	
	
	//PARTICIPANTES================================================
	Participante.cod = 1;
	strcpy(Participante.desc, "Denner");
	Participante.status = 'A';		
	fwrite(&Participante, sizeof(tPart), 1, pPart);
	
	Participante.cod = 2;
	strcpy(Participante.desc, "Gabriel");
	Participante.status = 'A';		
	fwrite(&Participante, sizeof(tPart), 1, pPart);
	
	Participante.cod = 3;
	strcpy(Participante.desc, "Gerson");
	Participante.status = 'A';		
	fwrite(&Participante, sizeof(tPart), 1, pPart);
	
	Participante.cod = 4;
	strcpy(Participante.desc, "Thiago");
	Participante.status = 'A';		
	fwrite(&Participante, sizeof(tPart), 1, pPart);
	
	
	//CAMPEONATOS==================================================
	Campeonato.codC = 1;
	strcpy(Campeonato.titulo, "Mundial de LoL");
	strcpy(Campeonato.responsavel, "Riot Games");
	Campeonato.ano = 2019;
	Campeonato.codJ = 1;
	strcpy(Campeonato.desc, "O torneio mais importante do MOBA da Riot Games...");
	Campeonato.status = 'A';
	fwrite(&Campeonato, sizeof(tCamp), 1, pCamp);
	
	Campeonato.codC = 2;
	strcpy(Campeonato.titulo, "Copa do Mundo de Fortnite");
	strcpy(Campeonato.responsavel, "Epic Games");
	Campeonato.ano = 2019;
	Campeonato.codJ = 2;
	strcpy(Campeonato.desc, "A jornada para a Fortnite World Cup...");
	Campeonato.status = 'A';
	fwrite(&Campeonato, sizeof(tCamp), 1, pCamp);
	
	Campeonato.codC = 3;
	strcpy(Campeonato.titulo, "Campeonato Brasileiro de CS:GO");
	strcpy(Campeonato.responsavel, "Valve");
	Campeonato.ano = 2020;
	Campeonato.codJ = 4;
	strcpy(Campeonato.desc, "Uma nova competicao de Counter-Strike...");
	Campeonato.status = 'A';
	fwrite(&Campeonato, sizeof(tCamp), 1, pCamp);
	
	Campeonato.codC = 4;
	strcpy(Campeonato.titulo, "Mata Kombat");
	strcpy(Campeonato.responsavel, "Warner Bros");
	Campeonato.ano = 2020;
	Campeonato.codJ = 3;
	strcpy(Campeonato.desc, "Competição de quem memorizou mais botões para combar!!!");
	Campeonato.status = 'A';
	fwrite(&Campeonato, sizeof(tCamp), 1, pCamp);
	
	//JOGADORES====================================================	
	Jogador.codC = 1;
	Jogador.codP = 1;
	strcpy(Jogador.nick, "friends");
	Jogador.status = 'A';
	fwrite(&Jogador, sizeof(tJogador), 1, pJogador);
	
	Jogador.codC = 1;
	Jogador.codP = 2;
	strcpy(Jogador.nick, "friends2");
	Jogador.status = 'A';
	fwrite(&Jogador, sizeof(tJogador), 1, pJogador);
	
	Jogador.codC = 2;
	Jogador.codP = 2;
	strcpy(Jogador.nick, "friends3");
	Jogador.status = 'A';
	fwrite(&Jogador, sizeof(tJogador), 1, pJogador);
	
	fclose(pJogo);
	fclose(pPart);
	fclose(pCamp);
	fclose(pJogador);
}	

void Apagar(int x)
{
	int i, y, j=83;
	
	if(x==1)
	{
		gotoxy(4,3);	printf("                                                                                    ");
	}
		
	for(i=6;i<27;i++)	
	{
		gotoxy(4,i);	printf("                                                                                    ");
	}
}

void Bordar(int xi, int xf, int yi, int yf)
{
	int i;
	
	gotoxy(xi,yi);		printf("%c",201);
	gotoxy(xf,yi);		printf("%c",187);
	gotoxy(xi,yf);		printf("%c",200);
	gotoxy(xf,yf);		printf("%c",188);
	
	for(i=xi+1;i<xf;i++)
	{
		gotoxy(i,yi);	printf("%c",205);
		gotoxy(i,yf);	printf("%c",205);
	}
	for(i=yi+1;i<yf;i++)
	{
		gotoxy(xi,i);	printf("%c",186);
		gotoxy(xf,i);	printf("%c",186);
	}
}	

void Bordarear(int x)
{
	
	Apagar(x);
	Bordar(1, 90, 1, 28);
	Bordar(3, 88, 2, 4);
	Bordar(3, 88, 5, 27);
	
//	Bordar(1, 120, 1, 28);
//	Bordar(3, 118, 2, 4);
//	Bordar(3, 118, 5, 27);

//OBS: MUDAR "J" NA FUNCAO "VOID APAGAR(INT X)"

}

char menu(void)
{
	gotoxy(5,6);	printf("[A]Cadastros");
	gotoxy(5,7);	printf("[B]Relatorios");
	gotoxy(5,8);	printf("[ESC]Sair");
	
	return toupper(getch());
}

char menuTipos(void)
{
	gotoxy(5,6);	printf("[A]Jogo");
	gotoxy(5,7);	printf("[B]Participante");
	gotoxy(5,8);	printf("[C]Campeonato");
	gotoxy(5,9);	printf("[D]Jogador");
	gotoxy(5,10);	printf("[ESC]Sair");
	
	return toupper(getch());
}

char menuCadastros(void)
{
	gotoxy(5,6);	printf("[A]Cadastrar");
	gotoxy(5,7);	printf("[B]Alterar");
	gotoxy(5,8);	printf("[C]Excluir");
	gotoxy(5,9);	printf("[D]Consultar");
	gotoxy(5,10);	printf("[ESC]Sair");
	
	return toupper(getch());
}

char menuRelatorios(void)
{
	gotoxy(5,6);	printf("[A]Relatorio Geral");
	gotoxy(5,7);	printf("[B]Relatorio Expecifico1");
	gotoxy(5,8);	printf("[C]Relatorio Expecifico2");
	gotoxy(5,9);	printf("[ESC]Sair");
	
	return toupper(getch());	
}

void exclusaofisica()
{
	FILE *pOld = fopen("aJogo.dat","rb");
	FILE *pNew = fopen("aNew.dat","wb");
	tJogo jogo;
	tCamp camp;
	tPart part;
	tJogador jogador;
	
	rewind(pOld);
	fread(&jogo, sizeof(tJogo), 1, pOld);
	while(!feof(pOld))
	{
		if(jogo.status == 'A')
			fwrite(&jogo, sizeof(tJogo), 1, pNew);

		fread(&jogo, sizeof(tJogo), 1, pOld);
	}
	
	fclose(pOld);
	fclose(pNew);
	
	remove("aJogo.dat");
	rename("aNew.dat","aJogo.dat");
	
	
	pOld = fopen("aCamp.dat","rb");
	pNew = fopen("aNew.dat","wb");
	
	rewind(pOld);
	fread(&camp, sizeof(tCamp), 1, pOld);
	while(!feof(pOld))
	{
		if(camp.status == 'A')
			fwrite(&camp, sizeof(tCamp), 1, pNew);
		
		
		fread(&camp, sizeof(tCamp), 1, pOld);
	}
	
	fclose(pOld);
	fclose(pNew);
	
	remove("aCamp.dat");
	rename("aNew.dat","aCamp.dat");
	
	rewind(pOld);
	pOld = fopen("aPart.dat","rb");
	pNew = fopen("aNew.dat","wb");
	
	fread(&part, sizeof(tPart), 1, pOld);
	while(!feof(pOld))
	{
		if(part.status == 'A')
			fwrite(&part, sizeof(tPart), 1, pNew);
		
			
		fread(&part, sizeof(tPart), 1, pOld);
	}
	
	fclose(pOld);
	fclose(pNew);
	
	remove("aPart.dat");
	rename("aNew.dat","aPart.dat");
	
	rewind(pOld);
	pOld = fopen("aJogador.dat","rb");
	pNew = fopen("aNew.dat","wb");
	
	fread(&jogador, sizeof(tJogador), 1, pOld);
	while(!feof(pOld))
	{
		if(jogador.status == 'A')
			fwrite(&jogador, sizeof(tJogador), 1, pNew);
			
		fread(&jogador, sizeof(tJogador), 1, pOld);
	}
	
	fclose(pOld);
	fclose(pNew);
	
	remove("aJogador.dat");
	rename("aNew.dat","aJogador.dat");
}

void exclusaofisicaJogo()
{
	FILE *pOld = fopen("aJogo.dat","rb");
	FILE *pNew = fopen("aNew.dat","wb");
	tJogo jogo;
	
	rewind(pOld);
	fread(&jogo, sizeof(tJogo), 1, pOld);
	while(!feof(pOld))
	{
		if(jogo.status == 'A')
			fwrite(&jogo, sizeof(tJogo), 1, pNew);

		fread(&jogo, sizeof(tJogo), 1, pOld);
	}
	
	fclose(pOld);
	fclose(pNew);
	
	remove("aJogo.dat");
	rename("aNew.dat","aJogo.dat");
}

void exclusaofisicaPart()
{
	FILE *pOld = fopen("aPart.dat","rb");
	FILE *pNew = fopen("aNew.dat","wb");
	tPart part;
	
	rewind(pOld);
	fread(&part, sizeof(tPart), 1, pOld);
	while(!feof(pOld))
	{
		if(part.status == 'A')
			fwrite(&part, sizeof(tPart), 1, pNew);

		fread(&part, sizeof(tPart), 1, pOld);
	}
	
	fclose(pOld);
	fclose(pNew);
	
	remove("aPart.dat");
	rename("aNew.dat","aPart.dat");
}

void exclusaofisicaCamp()
{
	FILE *pOld = fopen("aCamp.dat","rb");
	FILE *pNew = fopen("aNew.dat","wb");
	tCamp camp;
	
	rewind(pOld);
	fread(&camp, sizeof(tCamp), 1, pOld);
	while(!feof(pOld))
	{
		if(camp.status == 'A')
			fwrite(&camp, sizeof(tCamp), 1, pNew);

		fread(&camp, sizeof(tCamp), 1, pOld);
	}
	
	fclose(pOld);
	fclose(pNew);
	
	remove("aCamp.dat");
	rename("aNew.dat","aCamp.dat");
}

void exclusaofisicaJogador()
{
	FILE *pOld = fopen("aJogador.dat","rb");
	FILE *pNew = fopen("aNew.dat","wb");
	tJogador jogador;
	
	rewind(pOld);
	fread(&jogador, sizeof(tJogador), 1, pOld);
	while(!feof(pOld))
	{
		if(jogador.status == 'A')
			fwrite(&jogador, sizeof(tJogador), 1, pNew);

		fread(&jogador, sizeof(tJogador), 1, pOld);
	}
	
	fclose(pOld);
	fclose(pNew);
	
	remove("aJogador.dat");
	rename("aNew.dat","aJogador.dat");
}

int BuscaJogobin(FILE*pJogo, char aux[50])
{
	tJogo jogo;
	
	int inicio = 0, meio = 0, fim = 0;
	
	fseek(pJogo,0,2);
	fim = ftell(pJogo)/sizeof(tJogo)-1;
	meio = fim/2;
	
	fseek(pJogo, meio*sizeof(tJogo),0);
	fread(&jogo, sizeof(tJogo), 1, pJogo);
	while(inicio<fim && (stricmp(jogo.desc, aux)!=0 || jogo.status != 'A'))
	{
		if(stricmp(jogo.desc, aux) < 0)
			inicio = meio+1;
		else
			fim = meio-1;
		
		meio=(inicio+fim)/2;
		fseek(pJogo, meio*sizeof(tJogo), 0);
		fread(&jogo, sizeof(tJogo), 1, pJogo);
	}
	
	if(stricmp(jogo.desc,aux) == 0 && jogo.status == 'A')
		return meio*sizeof(tJogo);
	return -1;
}

int buscaJogoindex(FILE *pJogo,int code)
{
	tJogo jogo;
	
	rewind(pJogo);	
	fread(&jogo,sizeof(tJogo),1,pJogo);
	
	while(!feof(pJogo) && (code > jogo.cod || jogo.status!='A'))
		fread(&jogo,sizeof(tJogo),1,pJogo);
	
	if(!feof(pJogo) && code == jogo.cod)
		return ftell(pJogo)-sizeof(tJogo);
	else
		return -1;
}

int buscaJogoexaust(FILE *pJogo,int code)
{
	tJogo jogo;
	
	rewind(pJogo);	
	fread(&jogo,sizeof(tJogo),1,pJogo);
	
	while(!feof(pJogo) && (code != jogo.cod || jogo.status!='A'))
		fread(&jogo,sizeof(tJogo),1,pJogo);
	
	if(!feof(pJogo))
		return ftell(pJogo)-sizeof(tJogo);
	else
		return -1;
}

int BuscaJogosent(FILE *pJogo,char nome[50])
{
	FILE *itJogo = fopen("aJogo.dat", "ab");
	tJogo jogo;
	
	jogo.cod = 0;
	strcpy(jogo.desc,nome);
	jogo.status = 'I';
	fseek(itJogo,0,2);
	fwrite(&jogo,sizeof(tJogo),1,itJogo);
	fclose(itJogo);
	
	rewind(pJogo);
	fread(&jogo,sizeof(tJogo),1,pJogo);
	while(stricmp(nome,jogo.desc)!=0)
		fread(&jogo,sizeof(tJogo),1,pJogo);
	
	if(jogo.cod != 0 && jogo.status == 'A')
		return ftell(pJogo)-sizeof(tJogo);
	else
		return -1;
}

int BuscaPartbin(FILE*pPart, char aux[50])
{
	tPart part;
	
	int inicio = 0, meio = 0, fim = 0;
	
	fseek(pPart,0,2);
	fim = ftell(pPart)/sizeof(tPart)-1;
	meio = fim/2;
	
	fseek(pPart, meio*sizeof(tPart),0);
	fread(&part, sizeof(pPart), 1, pPart);
	while(inicio<fim && (stricmp(part.desc, aux)!=0 || part.status != 'A'))
	{
		if(stricmp(part.desc, aux) < 0)
			inicio = meio+1;
		else
			fim = meio-1;
		
		meio=(inicio+fim)/2;
		fseek(pPart, meio*sizeof(tPart), 0);
		fread(&part, sizeof(tPart), 1, pPart);
	}
	
	if(stricmp(part.desc,aux) == 0 && part.status == 'A')
		return meio*sizeof(tPart);
	return -1;
}

int buscaPartindex(FILE *pPart,int code)
{
	tPart part;
	
	rewind(pPart);
	fread(&part,sizeof(tPart),1,pPart);
	while(!feof(pPart) && (code > part.cod || part.status!='A'))
		fread(&part,sizeof(tPart),1,pPart);
	
	if(!feof(pPart) && code == part.cod)
		return ftell(pPart)-sizeof(tPart);
	else
		return -1;
}

int buscaPartexaust(FILE *pPart,int code)
{
	tPart part;
	
	rewind(pPart);
	fread(&part,sizeof(tPart),1,pPart);
	
	while(!feof(pPart) && (code != part.cod || part.status!='A'))
	{
		fread(&part,sizeof(tPart),1,pPart);
	}
	
	if(!feof(pPart))
		return ftell(pPart)-sizeof(tPart);
	else
		return -1;
}

int BuscaPartsent(FILE *pPart,char nome[50])
{
	FILE *itPart = fopen("aPart.dat", "ab");
	tPart part;
	
	part.cod = 0;
	strcpy(part.desc,nome);
	part.status = 'I';
	fseek(itPart,0,2);
	fwrite(&part,sizeof(tPart),1,itPart);
	fclose(itPart);
	
	rewind(pPart);
	fread(&part,sizeof(tPart),1,pPart);
	while(stricmp(nome,part.desc)!=0)
		fread(&part,sizeof(tPart),1,pPart);
	
	if(part.cod != 0 && part.status == 'A')
		return ftell(pPart)-sizeof(tPart);
	else
		return -1;
}

int BuscaJogadorbin(FILE*pJogador, char aux[50],int code)
{
	tJogador jogador;
	
	int inicio = 0, meio = 0, fim = 0;
	
	fseek(pJogador,0,2);
	fim = ftell(pJogador)/sizeof(tJogador)-1;
	meio = fim/2;
	
	fseek(pJogador, meio*sizeof(tJogador),0);
	fread(&jogador, sizeof(pJogador), 1, pJogador);
	while(inicio<fim && (stricmp(jogador.nick, aux)!=0 || jogador.codC != code || jogador.status != 'A'))
	{
		if(stricmp(jogador.nick, aux) < 0)
			inicio = meio+1;
		else
			fim = meio-1;
		
		meio=(inicio+fim)/2;
		fseek(pJogador, meio*sizeof(tJogador), 0);
		fread(&jogador, sizeof(tJogador), 1, pJogador);
	}
	
	if(stricmp(jogador.nick,aux) == 0 && jogador.status == 'A')
		return meio*sizeof(tJogador);
	return -1;
}

int buscaJogadorindex(FILE *pJogador,int code,int code2)
{
	tJogador jogador;
	
	rewind(pJogador);
	fread(&jogador,sizeof(tJogador),1,pJogador);
	while(!feof(pJogador) && (code != jogador.codP || code2 > jogador.codC || jogador.status!='A'))
		fread(&jogador,sizeof(tJogador),1,pJogador);
	
	if(!feof(pJogador) && code2 == jogador.codC && code == jogador.codP)
		return ftell(pJogador)-sizeof(tJogador);
	else
		return -1;
}

int buscaJogadorexaust(FILE *pJogador,int code,int code2)
{
	tJogador jogador;
	
	rewind(pJogador);
	fread(&jogador,sizeof(tJogador),1,pJogador);
	while(!feof(pJogador) && (code != jogador.codP || code2 != jogador.codC || jogador.status!='A'))
		fread(&jogador,sizeof(tJogador),1,pJogador);
	
	if(!feof(pJogador))
		return ftell(pJogador)-sizeof(tJogador);
	else
		return -1;
}

int BuscaJogadorsent(FILE *pJogador,char nome[50],int code)
{
	FILE *itJogador = fopen("aJogador.dat", "ab");
	tJogador jogador;
	
	jogador.codP = 0;
	jogador.codC = code;
	strcpy(jogador.nick,nome);
	jogador.status = 'I';
	fseek(itJogador,0,2);
	fwrite(&jogador,sizeof(tJogador),1,itJogador);
	fclose(itJogador);
	
	rewind(pJogador);
	fread(&jogador,sizeof(tJogador),1,pJogador);
	while(stricmp(nome,jogador.nick)!=0 || jogador.codC != code)
		fread(&jogador,sizeof(tJogador),1,pJogador);
	
	if(jogador.codP != 0 && jogador.status == 'A')
		return ftell(pJogador)-sizeof(tJogador);
	else
		return -1;
}

int BuscaCampbin(FILE*pCamp, char aux[50])
{
	tCamp camp;
	
	int inicio = 0, meio = 0, fim = 0;
	
	fseek(pCamp,0,2);
	fim = ftell(pCamp)/sizeof(tCamp)-1;
	meio = fim/2;
	
	fseek(pCamp, meio*sizeof(tCamp),0);
	fread(&camp, sizeof(pCamp), 1, pCamp);
	while(inicio<fim && (stricmp(camp.titulo, aux)!=0 || camp.status != 'A'))
	{
		if(stricmp(camp.titulo, aux) < 0)
			inicio = meio+1;
		else
			fim = meio-1;
		
		meio=(inicio+fim)/2;
		fseek(pCamp, meio*sizeof(tCamp), 0);
		fread(&camp, sizeof(tCamp), 1, pCamp);
	}
	
	if(stricmp(camp.titulo,aux) == 0 && camp.status =='A')
		return meio*sizeof(tCamp);
	return -1;
}

int buscaCampindex(FILE *pCamp,int code)
{
	tCamp camp;
	
	rewind(pCamp);
	fread(&camp,sizeof(tCamp),1,pCamp);
	while(!feof(pCamp) && (camp.codC < code || camp.status!='A'))
		fread(&camp,sizeof(tCamp),1,pCamp);
	
	if(!feof(pCamp) && camp.codC == code)
		return ftell(pCamp)-sizeof(tCamp);
	else
		return -1;
}

int buscaCampexaust(FILE *pCamp,int code)
{
	tCamp camp;
	
	rewind(pCamp);
	fread(&camp,sizeof(tCamp),1,pCamp);
	while(!feof(pCamp) && (camp.codC != code || camp.status!='A'))
		fread(&camp,sizeof(tCamp),1,pCamp);
	
	if(!feof(pCamp))
		return ftell(pCamp)-sizeof(tCamp);
	else
		return -1;
}

int BuscaCampsent(FILE *pCamp,char nome[50])
{
	FILE *itCamp = fopen("aCamp.dat", "ab");
	tCamp camp;
	
	camp.codC = 0;
	strcpy(camp.titulo,nome);
	camp.status = 'I';
	strcpy(camp.desc,"a");
	camp.codJ = 0;
	camp.ano = 0;
	strcpy(camp.responsavel,"a");

	fseek(itCamp,0,2);
	fwrite(&camp,sizeof(tCamp),1,itCamp);
	fclose(itCamp);
	
	rewind(pCamp);
	fread(&camp,sizeof(tCamp),1,pCamp);
	while(stricmp(nome,camp.titulo)!=0)
		fread(&camp,sizeof(tCamp),1,pCamp);
	
	if(camp.codC != 0 && camp.status == 'A')
		return ftell(pCamp)-sizeof(tCamp);
	else
		return -1;
}

void ordenarCampbubble()
{
	FILE* pCamp = fopen("aCamp.dat", "rb+");
	tCamp camp1, camp2;
	int flag = 1,TL,i;
	
	fseek(pCamp,0,2);
	TL = ftell(pCamp)/sizeof(tCamp);
	while(TL>1 && flag==1)
	{
		flag = 0;
		for(i=0;i<TL-1;i++)
		{
			fseek(pCamp,i*sizeof(tCamp),0);
			fread(&camp1,sizeof(tCamp),1,pCamp);
			fread(&camp2,sizeof(tCamp),1,pCamp);
			if(camp1.codC > camp2.codC && camp2.status == 'A' || camp1.status == 'I')
			{
				flag = 1;
				fseek(pCamp,i*sizeof(tCamp),0);
				fwrite(&camp2,sizeof(tCamp),1,pCamp);
				fwrite(&camp1,sizeof(tCamp),1,pCamp);
			}
		}
		TL--;
	}
	
	fclose(pCamp);
}

void ordenarCampinserction()
{
	FILE* pCamp = fopen("aCamp.dat", "rb+");
	tCamp camp1, camp2;
	int TL;
	
	fseek(pCamp,0,2);
	TL = (ftell(pCamp)/sizeof(tCamp))-1;
	
	if(TL > 0)
	{
		fseek(pCamp,(TL-1)*sizeof(tCamp),0);
		fread(&camp1,sizeof(tCamp),1,pCamp);
		fread(&camp2,sizeof(tCamp),1,pCamp);
		if(camp1.codC > camp2.codC || camp1.status == 'I')
		{
			fseek(pCamp,(TL-1)*sizeof(tCamp),0);
			fwrite(&camp2,sizeof(tCamp),1,pCamp);
			fwrite(&camp1,sizeof(tCamp),1,pCamp);
		}
		TL--;
	}
	
	
	while(TL>0 && camp1.codC > camp2.codC)
	{

		fseek(pCamp,(TL-1)*sizeof(tCamp),0);
		fread(&camp1,sizeof(tCamp),1,pCamp);
		fread(&camp2,sizeof(tCamp),1,pCamp);
		if(camp1.codC > camp2.codC || camp1.status == 'I')
		{
			fseek(pCamp,(TL-1)*sizeof(tCamp),0);
			fwrite(&camp2,sizeof(tCamp),1,pCamp);
			fwrite(&camp1,sizeof(tCamp),1,pCamp);
		}
		TL--;
	}
	
	fclose(pCamp);
}

void ordenarCampselection()
{
	FILE* pCamp = fopen("aCamp.dat", "rb+");
	tCamp camp, maior;
	int flag = 1,TL,i,pos;
	
	fseek(pCamp,0,2);
	TL = ftell(pCamp)/sizeof(tCamp);
	while(TL>1 && flag==1)
	{
		flag = 0;
		fseek(pCamp,0,0);
		fread(&maior,sizeof(tCamp),1,pCamp);
		pos = 0;
		
		for(i=1;i<TL;i++)
		{
			fseek(pCamp,i*sizeof(tCamp),0);
			fread(&camp,sizeof(tCamp),1,pCamp);
			
			if(stricmp(maior.titulo,camp.titulo) < 0 && maior.status == 'A' || camp.status == 'I')
			{
				maior = camp;
				pos = i;
			}
			else
				flag = 1;
		}
		fseek(pCamp,pos*sizeof(tCamp),0);
		fwrite(&camp,sizeof(tCamp),1,pCamp);
		fseek(pCamp,(TL-1)*sizeof(tCamp),0);
		fwrite(&maior,sizeof(tCamp),1,pCamp);
		
		TL--;
	}
	
	fclose(pCamp);
}

void ordenarJogobubble()
{
	FILE* pJogo = fopen("aJogo.dat", "rb+");
	tJogo jogo1,jogo2;
	int flag = 1,TL,i;
	
	fseek(pJogo,0,2);
	TL = ftell(pJogo)/sizeof(tJogo);
	while(TL>1 && flag==1)
	{
		flag = 0;
		for(i=0;i<TL-1;i++)
		{
			fseek(pJogo,i*sizeof(tJogo),0);
			fread(&jogo1,sizeof(tJogo),1,pJogo);
			fread(&jogo2,sizeof(tJogo),1,pJogo);
			if(jogo1.cod > jogo2.cod)
			{
				flag = 1;
				fseek(pJogo,i*sizeof(tJogo),0);
				fwrite(&jogo2,sizeof(tJogo),1,pJogo);
				fwrite(&jogo1,sizeof(tJogo),1,pJogo);
			}
		}
		TL--;
	}
	
	fclose(pJogo);
}

void ordenarJogoinserction()
{
	FILE* pJogo = fopen("aJogo.dat", "rb+");
	tJogo jogo1, jogo2;
	int TL;
	
	fseek(pJogo,0,2);
	TL = (ftell(pJogo)/sizeof(tJogo))-1;
	
	if(TL > 0)
	{
		fseek(pJogo,(TL-1)*sizeof(tJogo),0);
		fread(&jogo1,sizeof(tJogo),1,pJogo);
		fread(&jogo2,sizeof(tJogo),1,pJogo);
		
		if(jogo1.cod > jogo2.cod)
		{
			fseek(pJogo,(TL-1)*sizeof(tJogo),0);
			fwrite(&jogo2,sizeof(tJogo),1,pJogo);
			fwrite(&jogo1,sizeof(tJogo),1,pJogo);
		}
		TL--;
	}
	
	
	while(TL>0 && jogo1.cod > jogo2.cod)
	{

		fseek(pJogo,(TL-1)*sizeof(tJogo),0);
		fread(&jogo1,sizeof(tJogo),1,pJogo);
		fread(&jogo2,sizeof(tJogo),1,pJogo);
		if(jogo1.cod > jogo2.cod)
		{
			fseek(pJogo,(TL-1)*sizeof(tJogo),0);
			fwrite(&jogo2,sizeof(tJogo),1,pJogo);
			fwrite(&jogo1,sizeof(tJogo),1,pJogo);
		}
		TL--;
	}
	
	fclose(pJogo);
}

void ordenarJogoselection()
{
	FILE* pJogo = fopen("aJogo.dat", "rb+");
	tJogo jogo, maior;
	int flag = 1,TL,i,pos;
	
	fseek(pJogo,0,2);
	TL = ftell(pJogo)/sizeof(tJogo);
	while(TL>1 && flag==1)
	{
		flag = 0;
		fseek(pJogo,0,0);
		fread(&maior,sizeof(tJogo),1,pJogo);
		pos = 0;
		
		for(i=1;i<TL;i++)
		{
			fseek(pJogo,i*sizeof(tJogo),0);
			fread(&jogo,sizeof(tJogo),1,pJogo);
			
			if(stricmp(maior.desc,jogo.desc) < 0)
			{
				maior = jogo;
				pos = i;
			}
			else
				flag = 1;
		}
		fseek(pJogo,pos*sizeof(tJogo),0);
		fwrite(&jogo,sizeof(tJogo),1,pJogo);
		fseek(pJogo,(TL-1)*sizeof(tJogo),0);
		fwrite(&maior,sizeof(tJogo),1,pJogo);
		
		TL--;
	}
	
	fclose(pJogo);
}

void ordenarJogadorbubble()
{
	FILE* pJogador = fopen("aJogador.dat", "rb+");
	tJogador jogador1,jogador2;
	int flag = 1,TL,i;
	
	fseek(pJogador,0,2);
	TL = ftell(pJogador)/sizeof(tJogador);
	while(TL>1 && flag==1)
	{
		flag = 0;
		for(i=0;i<TL-1;i++)
		{
			fseek(pJogador,i*sizeof(tJogador),0);
			fread(&jogador1,sizeof(tJogador),1,pJogador);
			fread(&jogador2,sizeof(tJogador),1,pJogador);
			if(jogador1.codC > jogador2.codC)
			{
				flag = 1;
				fseek(pJogador,i*sizeof(tJogador),0);
				fwrite(&jogador2,sizeof(tJogador),1,pJogador);
				fwrite(&jogador1,sizeof(tJogador),1,pJogador);
			}
		}
		TL--;
	}
	
	fclose(pJogador);
}

void ordenarJogadorinserction()
{
	FILE* pJogador = fopen("aJogador.dat", "rb+");
	tJogador jogador1, jogador2;
	int TL;
	
	fseek(pJogador,0,2);
	TL = (ftell(pJogador)/sizeof(tJogador))-1;

	if(TL > 0)
	{
		fseek(pJogador,(TL-1)*sizeof(tJogador),0);
		fread(&jogador1,sizeof(tJogador),1,pJogador);
		fread(&jogador2,sizeof(tJogador),1,pJogador);
		if(jogador1.codC > jogador2.codC)
		{
			fseek(pJogador,(TL-1)*sizeof(tJogador),0);
			fwrite(&jogador2,sizeof(tJogador),1,pJogador);
			fwrite(&jogador1,sizeof(tJogador),1,pJogador);
		}
		TL--;
	}
	
	while(TL>0 && jogador1.codC > jogador2.codC)
	{

		fseek(pJogador,(TL-1)*sizeof(tJogador),0);
		fread(&jogador1,sizeof(tJogador),1,pJogador);
		fread(&jogador2,sizeof(tJogador),1,pJogador);
		if(jogador1.codC > jogador2.codC)
		{
			fseek(pJogador,(TL-1)*sizeof(tJogador),0);
			fwrite(&jogador2,sizeof(tJogador),1,pJogador);
			fwrite(&jogador1,sizeof(tJogador),1,pJogador);
		}
		TL--;
	}
	
	fclose(pJogador);
}

void ordenarJogadorselection()
{
	FILE* pJogador = fopen("aJogador.dat", "rb+");
	tJogador jogador, maior;
	int flag = 1,TL,i,pos;
	
	fseek(pJogador,0,2);
	TL = ftell(pJogador)/sizeof(tJogador);
	while(TL>1 && flag==1)
	{
		flag = 0;
		fseek(pJogador,0,0);
		fread(&maior,sizeof(tJogador),1,pJogador);
		pos = 0;
		
		for(i=1;i<TL;i++)
		{
			fseek(pJogador,i*sizeof(tJogador),0);
			fread(&jogador,sizeof(tJogador),1,pJogador);
			
			if(stricmp(maior.nick,jogador.nick) < 0)
			{
				maior = jogador;
				pos = i;
			}
			else
				flag = 1;
		}
		fseek(pJogador,pos*sizeof(tJogador),0);
		fwrite(&jogador,sizeof(tJogador),1,pJogador);
		fseek(pJogador,(TL-1)*sizeof(tJogador),0);
		fwrite(&maior,sizeof(tJogador),1,pJogador);
		
		TL--;
	}
	
	fclose(pJogador);
}

void ordenarPartbubble()
{
	FILE* pPart = fopen("aPart.dat", "rb+");
	tPart part1,part2;
	int flag = 1,TL,i;
	
	fseek(pPart,0,2);
	TL = ftell(pPart)/sizeof(tPart);
	while(TL>1 && flag==1)
	{
		flag = 0;
		for(i=0;i<TL-1;i++)
		{
			fseek(pPart,i*sizeof(tPart),0);
			fread(&part1,sizeof(tPart),1,pPart);
			fread(&part2,sizeof(tPart),1,pPart);
			if(part1.cod > part2.cod)
			{
				flag = 1;
				fseek(pPart,i*sizeof(tPart),0);
				fwrite(&part2,sizeof(tPart),1,pPart);
				fwrite(&part1,sizeof(tPart),1,pPart);
			}
		}
		TL--;
	}
	
	fclose(pPart);
}

void ordenarPartinserction()
{	
	FILE* pPart = fopen("aPart.dat", "rb+");
	tPart part1, part2;
	int TL;
	
	fseek(pPart,0,2);
	TL = (ftell(pPart)/sizeof(tPart))-1;
	
	if(TL > 0)
	{
		fseek(pPart,(TL-1)*sizeof(tPart),0);
		fread(&part1,sizeof(tPart),1,pPart);
		fread(&part2,sizeof(tPart),1,pPart);
		if(part1.cod > part2.cod)
		{
			fseek(pPart,(TL-1)*sizeof(tPart),0);
			fwrite(&part2,sizeof(tPart),1,pPart);
			fwrite(&part1,sizeof(tPart),1,pPart);
		}
		TL--;
	}
	
	
	while(TL>0 && part1.cod > part2.cod)
	{

		fseek(pPart,(TL-1)*sizeof(tPart),0);
		fread(&part1,sizeof(tPart),1,pPart);
		fread(&part2,sizeof(tPart),1,pPart);
		if(part1.cod > part2.cod)
		{
			fseek(pPart,(TL-1)*sizeof(tPart),0);
			fwrite(&part2,sizeof(tPart),1,pPart);
			fwrite(&part1,sizeof(tPart),1,pPart);
		}
		TL--;
	}
	
	fclose(pPart);
}

void ordenarPartselection()
{	
	FILE* pPart = fopen("aPart.dat", "rb+");
	tPart part, maior;
	int flag = 1,TL,i,pos;
	
	fseek(pPart,0,2);
	TL = ftell(pPart)/sizeof(tPart);
	while(TL>1 && flag==1)
	{
		flag = 0;
		fseek(pPart,0,0);
		fread(&maior,sizeof(tPart),1,pPart);
		pos = 0;
		
		for(i=1;i<TL;i++)
		{
			fseek(pPart,i*sizeof(tPart),0);
			fread(&part,sizeof(tPart),1,pPart);
			
			if(stricmp(maior.desc,part.desc) < 0)
			{
				maior = part;
				pos = i;
			}
			else
				flag = 1;
		}
		fseek(pPart,pos*sizeof(tPart),0);
		fwrite(&part,sizeof(tPart),1,pPart);
		fseek(pPart,(TL-1)*sizeof(tPart),0);
		fwrite(&maior,sizeof(tPart),1,pPart);
		
		TL--;
	}
	
	fclose(pPart);
}

void CadastrarJogo()
{
	FILE *pJogo = fopen("aJogo.dat","ab+");
	tJogo jogo;
	
	int	pos;
	
	gotoxy(5,20);	printf("Digite codigo ou digite 0 para sair: ");
	scanf("%d",&jogo.cod);
	
	while(jogo.cod != 0)
	{
		Apagar(0);
		pos = buscaJogoindex(pJogo, jogo.cod);
		
		if(pos == -1)
		{
			gotoxy(5,21);	printf("Digite o nome: ");
			fflush(stdin);
			gets(jogo.desc);
			pos = BuscaJogosent(pJogo, jogo.desc);
			
			fclose(pJogo);
			exclusaofisicaJogo();
			pJogo = fopen("aJogo.dat","ab+");
			
			if(pos == -1)
			{
				Apagar(0);
				jogo.status='A';
				fseek(pJogo, 0, 2);
				fwrite(&jogo, sizeof(tJogo), 1, pJogo);
				gotoxy(5,14);	printf("%s cadastrado com sucesso!", jogo.desc);
				
				fclose(pJogo);
				ordenarJogoinserction();
				pJogo = fopen("aJogo.dat","ab+");
				
				getch();
			}
			else
			{
				Apagar(0);
				gotoxy(5,14);	printf("%s ja existe!", jogo.desc);
				getch();
			}
		}
		else
		{
			Apagar(0);
			gotoxy(5,14);	printf("Codigo de jogo ja cadastrado!");
			getch();
		}
		Apagar(0);
		gotoxy(5,20);	printf("Digite codigo ou digite 0 para sair: ");
		scanf("%d",&jogo.cod);
	}
	fclose(pJogo);
}

void CadastrarPart()
{
	FILE *pPart = fopen("aPart.dat","ab+");
	tPart part;
	
	int	pos;
	
	gotoxy(5,20);	printf("Digite codigo ou digite 0 para sair: ");
	scanf("%d",&part.cod);
	
	while(part.cod != 0)
	{
		pos = buscaPartexaust(pPart, part.cod);
		
		if(pos == -1)
		{
			gotoxy(5,21);	printf("Digite o nome: ");
			fflush(stdin);
			gets(part.desc);
			pos = BuscaPartsent(pPart, part.desc);
			
			fclose(pPart);
			exclusaofisicaPart();
			pPart = fopen("aPart.dat","ab+");
			
			if(pos == -1)
			{
				part.status='A';
				fseek(pPart, 0, 2);
				fwrite(&part, sizeof(tPart), 1, pPart);
				
				fclose(pPart);
				ordenarPartbubble();
				pPart = fopen("aPart.dat","ab+");
				Apagar(0);
				gotoxy(5,14);	printf("%s cadastrado com sucesso", part.desc);
				getch();
			}
			else
			{
				Apagar(0);
				gotoxy(5,14);	printf("%s ja existe!", part.desc);
				getch();
			}
		}
		else
		{
			Apagar(0);
			gotoxy(5,14);	printf("Codigo de participante ja cadastrado");
			getch();
		}
		Apagar(0);
		gotoxy(5,20);	printf("Digite codigo ou digite 0 para sair: ");
		scanf("%d",&part.cod);
	}
	
	fclose(pPart);
}

void CadastrarCamp()
{
	FILE *pCamp = fopen("aCamp.dat","ab+");
	FILE *pJogo = fopen("aJogo.dat","rb");
	tCamp camp;
	tJogo jogo;
	
	int	pos;
	
	gotoxy(5,20);	printf("Digite codigo ou digite 0 para sair: ");
	scanf("%d",&camp.codC);
	
	while(camp.codC != 0)
	{
		pos = buscaCampexaust(pCamp, camp.codC);
		
		if(pos == -1)
		{
			gotoxy(5,21);	printf("Digite o nome do campeonato: ");
			fflush(stdin);
			gets(camp.titulo);
			pos = BuscaCampbin(pCamp, camp.titulo);
			
			if(pos == -1)
			{
				gotoxy(5,22);	printf("Digite o nome do jogo do campeonato: ");
				fflush(stdin);
				gets(jogo.desc);
				
				pos = BuscaJogosent(pJogo,jogo.desc);
				
				fclose(pCamp);
			    exclusaofisicaCamp();
			    pCamp = fopen("aCamp.dat","ab+");
				
				if(pos != -1)
				{
					fseek(pJogo,pos,0);
					fread(&jogo,sizeof(tJogo),1,pJogo);
					camp.codJ = jogo.cod;
					camp.status='A';
					gotoxy(5,23);	printf("Digite a descricao do campeonato: ");
					fflush(stdin);
					gets(camp.desc);
					gotoxy(5,24);	printf("Digite o responsavel do campeonato: ");
					fflush(stdin);
					gets(camp.responsavel);
					gotoxy(5,25);	printf("Digite o ano do campeonato: ");
					scanf("%d",&camp.ano);
					fseek(pCamp, 0, 2);
					fwrite(&camp, sizeof(tCamp), 1, pCamp);
					
					fclose(pJogo);
			    	fclose(pCamp);
					ordenarCampselection();
					pJogo = fopen("aJogo.dat","rb");
			        pCamp = fopen("aCamp.dat","ab+");
					
					Apagar(0);
					gotoxy(5,14);	printf("%s cadastrado com sucesso!", camp.titulo);
					getch();
				}
				else
				{
					Apagar(0);
					gotoxy(5,14);	printf("%s nao esta cadastrado!",jogo.desc);
					getch();
				}
			}
			else
			{
				Apagar(0);
				gotoxy(5,14);	printf("%s ja existe!", camp.titulo);
				getch();
			}
		}
		else
		{
			Apagar(0);
			gotoxy(5,14);	printf("Codigo de campeonato ja cadastrado!");
			getch();
		}
		Apagar(0);
		gotoxy(5,20);	printf("Digite codigo ou digite 0 para sair: ");
		scanf("%d",&camp.codC);
	}
	
	fclose(pCamp);
	fclose(pJogo);
}

void CadastrarJogador()
{
	FILE *pCamp = fopen("aCamp.dat","rb");
	FILE *pJogador = fopen("aJogador.dat","ab+");
	FILE *pPart = fopen("aPart.dat","rb");
	tCamp camp;
	tJogador jogador;
	tPart part;
	
	int	pos;
	
	gotoxy(5,20);	printf("Digite o nome do participante a cadastrar: ");
	fflush(stdin);
	gets(part.desc);
	
	while(strlen(part.desc)>0)
	{
		pos = BuscaPartsent(pPart,part.desc);	
		
		if(pos != -1)
		{
			fseek(pPart,pos,0);
			fread(&part,sizeof(tPart),1,pPart);// ERRO <------------------------------------------------
			
			gotoxy(5,21);	printf("Digite o nome do campeonato: ");
			fflush(stdin);
			gets(camp.titulo);
			pos = BuscaCampsent(pCamp, camp.titulo);
			
			if(pos != -1)
			{
				fseek(pCamp,pos,0);
				fread(&camp,sizeof(tCamp),1,pCamp);
				
				pos = buscaJogadorexaust(pJogador,part.cod,camp.codC);

				if(pos == -1)
				{
					gotoxy(5,22);	printf("Digite o nick do jogador no campeonato: ");
					fflush(stdin);
					gets(jogador.nick);
					pos = BuscaJogadorsent(pJogador,jogador.nick,camp.codC);
					if(pos == -1)
					{
						jogador.codC = camp.codC;
						jogador.codP = part.cod;
						jogador.status='A';
						fseek(pJogador, 0, 2);
						fwrite(&jogador, sizeof(tJogador), 1, pJogador);
						
						Apagar(0);
						gotoxy(5,14);	printf("%s cadastrado com sucesso!", jogador.nick);
						getch();
					}
					else
					{
						Apagar(0);
						gotoxy(5,14);	printf("%s ja existe!",jogador.nick);
						getch();
					}
				}
				else
				{
					Apagar(0);
					gotoxy(5,14);	printf("%s ja esta cadastrado neste campeonato!",part.desc);
					getch();
				}
			}
			else
			{
				Apagar(0);
				gotoxy(5,14);	printf("%s nao existe!", camp.titulo);
				getch();
			}
		}
		else
		{
			Apagar(0);
			gotoxy(5,14);	printf("%s nao esta cadastrado!", part.desc);
			getch();
		}
		Apagar(0);
		gotoxy(5,20);	printf("Digite o nome do participante a cadastrar: ");
		fflush(stdin);
		gets(part.desc);
	}
	
	fclose(pCamp);
	fclose(pJogador);
	fclose(pPart);
}

void exclusaologicaParticipante()
{
	FILE *pPart = fopen("aPart.dat","rb+");
	FILE *pJogador = fopen("aJogador.dat","rb+");
	tPart part;
	tJogador jogador;
	int pos, i;
	
	gotoxy(5,20);	printf("Digite codigo do participante a ser excluido: ");
	scanf("%d", &part.cod);
	
	pos = buscaPartexaust(pPart, part.cod);
	
	if(pos != -1)
	{
		fseek(pPart, pos, 0);
		fread(&part, sizeof(tPart), 1, pPart);
		part.status = 'I';
		fseek(pPart, pos, 0);
		fwrite(&part, sizeof(tPart), 1, pPart);
		
		i=0;
		fseek(pJogador, i*sizeof(tJogador), 0);	
		fread(&jogador, sizeof(tJogador), 1, pJogador);	
		while(!feof(pJogador))
		{
			if(jogador.codP == part.cod)
			{
				jogador.status = 'I';
				fseek(pJogador, i*sizeof(tJogador), 0);
				fwrite(&jogador, sizeof(tJogador), 1, pJogador);
			}
			i++;
			fseek(pJogador, i*sizeof(tJogador), 0);	
			fread(&jogador, sizeof(tJogador), 1, pJogador);
		}
		Apagar(0);
		gotoxy(5,14);	printf("Exclusao concluida!");
		getch();
	}
	else
	{
		Apagar(0);
		gotoxy(5,14);	printf("Codigo nao cadastrado");
		getch();
	}
	
	fclose(pPart);
	fclose(pJogador);
}

void exclusaologicaJogador()
{
	FILE *pJogador = fopen("aJogador.dat","rb+");
	tJogador jogador;
	int pos;
	
	gotoxy(5,20);	printf("Digite codigo do participante: ");
	scanf("%d", &jogador.codP);
	gotoxy(5,21);	printf("Digite codigo do campeonato do participante: ");
	scanf("%d", &jogador.codC);
	
	pos = buscaJogadorexaust(pJogador, jogador.codP, jogador.codC);
	if(pos != -1)
	{
		fseek(pJogador, pos, 0);
		fread(&jogador, sizeof(tJogador), 1, pJogador);
		
		jogador.status = 'I';
		fseek(pJogador, pos, 0);
		fwrite(&jogador, sizeof(tJogador), 1, pJogador);
		
		Apagar(0);
		gotoxy(5,14);	printf("Exclusao concluida!");
	}
	else
	{
		Apagar(0);
		gotoxy(5,14);	printf("Jogador nao encontrado!");
	}
	getch();
	fclose(pJogador);
}

void exclusaologicaCampeonato()
{
	FILE *pCamp = fopen("aCamp.dat","rb+");
	FILE *pJogador = fopen("aJogador.dat","rb+");
	tCamp camp;
	tJogador jogador;
	int pos, i;
	
	gotoxy(5,20);	printf("Digite o codigo do campeonato a ser excluido: ");
	scanf("%d", &camp.codC);
	
	pos = buscaCampexaust(pCamp, camp.codC);
	
	if(pos != -1)
	{
		fseek(pCamp, pos, 0);
		fread(&camp, sizeof(tCamp), 1, pCamp);
		camp.status = 'I';
		fseek(pCamp, pos, 0);
		fwrite(&camp, sizeof(tCamp), 1, pCamp);
		
		i=0;
		fseek(pJogador, i*sizeof(tJogador), 0);
		fread(&jogador, sizeof(tJogador), 1, pJogador);
		while(!feof(pJogador))
		{
			if(jogador.codC == camp.codC)
			{
				jogador.status = 'I';
				fseek(pJogador, i*sizeof(tJogador), 0);
				fwrite(&jogador, sizeof(tJogador), 1, pJogador);
			}
			
			i++;
			fseek(pJogador, i*sizeof(tJogador), 0);
			fread(&jogador, sizeof(tJogador), 1, pJogador);
		}
		Apagar(0);
		gotoxy(5,14);	printf("Exclusao concluida!");
		getch();
	}
	else
	{
		Apagar(0);
		gotoxy(5,14);printf("Codigo nao cadastrado!");
		getch();
	}
	fclose(pCamp);
	fclose(pJogador);
}

void exclusaologicaJogo()
{
	FILE *pJogo = fopen("aJogo.dat","rb+");
	FILE *pCamp = fopen("aCamp.dat","rb+");
	FILE *pJogador = fopen("aJogador.dat","rb+");
	tJogo jogo;
	tCamp camp;
	tJogador jogador;
	int pos,i,j;
	
	gotoxy(5,20);	printf("Digite o nome do jogo a ser excluido: ");
	fflush(stdin);
	gets(jogo.desc);
	
	pos = BuscaJogosent(pJogo,jogo.desc);
	if(pos != -1)
	{
		fseek(pJogo,pos,0);
		fread(&jogo,sizeof(tJogo),1,pJogo);
		jogo.status = 'I';
		fseek(pJogo,pos,0);
		fwrite(&jogo,sizeof(tJogo),1,pJogo);
		
		i = 0;
		fseek(pCamp,i*sizeof(tCamp),0);
		fread(&camp,sizeof(tCamp),1,pCamp);
		while(!feof(pCamp))
		{
			if(camp.codJ == jogo.cod)
			{
				camp.status = 'I';
				fseek(pCamp,i*sizeof(tCamp),0);
				fwrite(&camp,sizeof(tCamp),1,pCamp);
				
				j = 0;
				fseek(pJogador,j*sizeof(tJogador),0);
				fread(&jogador,sizeof(tJogador),1,pJogador);
				while(!feof(pJogador))
				{
					if(jogador.codC == camp.codC)
					{
						jogador.status = 'I';
						fseek(pJogador,j*sizeof(tJogador),0);
						fwrite(&jogador,sizeof(tJogador),1,pJogador);
					}
					j++;
					fseek(pJogador,j*sizeof(tJogador),0);
					fread(&jogador,sizeof(tJogador),1,pJogador);
				}
			}
			i++;
			fseek(pCamp,i*sizeof(tCamp),0);
			fread(&camp,sizeof(tCamp),1,pCamp);
		}
		Apagar(0);
		gotoxy(5,14);	printf("Exclusao concluida!");
		getch();
	}
	else
	{
		Apagar(0);
		gotoxy(5,14);printf("Jogo nao encontrado!");
		getch();
	}
	
	fclose(pJogo);
	fclose(pCamp);
	fclose(pJogador);
}

void alterarJogo()
{
	FILE *pJogo = fopen("aJogo.dat","rb+");
	tJogo jogo;
	int pos, i;
	
	gotoxy(5,20);	printf("Digite o codigo do nome do jogo a ser alterado: ");
	scanf("%d", &jogo.cod);
	
	pos = buscaJogoexaust(pJogo, jogo.cod);
	
	if(pos != -1)
	{
		fseek(pJogo,pos,0);
		fread(&jogo,sizeof(tJogo),1,pJogo);
		gotoxy(5,21);	printf("Nome atual: %s",jogo.desc);
		
		gotoxy(5,22);	printf("Digite novo nome: ");
		fflush(stdin);
		gets(jogo.desc);
		
		i = BuscaJogosent(pJogo, jogo.desc);
		
		if(i == -1)
		{
			fseek(pJogo, pos, 0);
			fwrite(&jogo, sizeof(tJogo), 1, pJogo);
			
			Apagar(0);
			gotoxy(5,12);	printf("%d - %s", jogo.cod, jogo.desc);
			gotoxy(5,14);	printf("Alteracao concluida!");
			getch();
		}
		else
		{
			Apagar(0);
			gotoxy(5,14);	printf("Jogo ja cadastrado!");
			getch();
		}
	}
	else
	{
		Apagar(0);
		gotoxy(5,14);	printf("Codigo nao cadastrado!");
		getch();
	}
	
	fclose(pJogo);
}

void alterarPart()
{
	FILE *pPart = fopen("aPart.dat","rb+");
	tPart part;
	int pos, i;
	
	Apagar(0);
	gotoxy(5,20);	printf("Digite o codigo do participante a ser alterado: ");
	scanf("%d", &part.cod);
	
	pos = buscaPartexaust(pPart, part.cod);
	
	if(pos != -1)
	{
		fseek(pPart,pos,0);
		fread(&part,sizeof(tPart),1,pPart);
		gotoxy(5,21);	printf("Nome atual: %s",part.desc);
		
		gotoxy(5,22);	printf("Digite novo nome: ");
		fflush(stdin);
		gets(part.desc);
		
		i = BuscaPartsent(pPart, part.desc);
		
		if(i == -1)
		{
			fseek(pPart, pos, 0);
			fwrite(&part, sizeof(tPart), 1, pPart);
			
			Apagar(0);
			gotoxy(5,12);	printf("%d - %s", part.cod, part.desc);
			gotoxy(5,14);	printf("Alteracao concluida!");
			getch();
		}
		else
		{
			Apagar(0);
			gotoxy(5,14);	printf("Jogo ja cadastrado!");
			getch();
		}
	}
	else
	{
		Apagar(0);
		gotoxy(5,14);	printf("Codigo nao cadastrado!");
		getch();
	}
	
	fclose(pPart);
}

void alterarCamp()
{
	FILE *pCamp = fopen("aCamp.dat","rb+");
	tCamp camp;
	char op;
	int pos;
	
	gotoxy(5,20);	printf("Digite o codigo do campeonato: ");
	scanf("%d",&camp.codC);
	
	pos = buscaCampexaust(pCamp,camp.codC);
	if(pos != -1)
	{
		fseek(pCamp,pos,0);
		fread(&camp,sizeof(tCamp),1,pCamp);
		
		do
		{
			Apagar(0);
			gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Campeonato  >>  Alterar ]>");
			gotoxy(5,12);	printf("%d - %s - %d - %s",camp.codC, camp.titulo, camp.ano, camp.responsavel);
			gotoxy(5,13);	printf("%s", camp.desc);
			
			gotoxy(5,6);	printf("[A]Titulo");
			gotoxy(5,7);	printf("[B]Ano");
			gotoxy(5,8);	printf("[C]Responsavel");
			gotoxy(5,9);	printf("[D]Descricao");
			gotoxy(5,10);	printf("[ESC] Sair");
		
			op = toupper(getche());
			switch(op)
			{
				case 'A':	Apagar(0);
							gotoxy(5,12);	printf("%d - %s - %d - %s",camp.codC, camp.titulo, camp.ano, camp.responsavel);
							gotoxy(5,13);	printf("%s", camp.desc);
							gotoxy(5,20);	printf("Digite o novo titulo: ");
							fflush(stdin);
							gets(camp.titulo);
							break;
							
				case 'B':	Apagar(0);
							gotoxy(5,12);	printf("%d - %s - %d - %s",camp.codC, camp.titulo, camp.ano, camp.responsavel);
							gotoxy(5,13);	printf("%s", camp.desc);
							gotoxy(5,20);	printf("Digite o novo ano: ");
							scanf("%d",&camp.ano);
							break;
							
				case 'C':	Apagar(0);
							gotoxy(5,12);	printf("%d - %s - %d - %s",camp.codC, camp.titulo, camp.ano, camp.responsavel);
							gotoxy(5,13);	printf("%s", camp.desc);
							gotoxy(5,20);	printf("Digite o novo responsavel: ");
							fflush(stdin);
							gets(camp.responsavel);
							break;
							
				case 'D':	Apagar(0);
							gotoxy(5,12);	printf("%d - %s - %d - %s",camp.codC, camp.titulo, camp.ano, camp.responsavel);
							gotoxy(5,13);	printf("%s", camp.desc);
							gotoxy(5,20);	printf("Digite a nova descricao: ");
							fflush(stdin);
							gets(camp.desc);
							break;
			}
		}while(op != 27);
		
		fseek(pCamp,pos,0);
		fwrite(&camp,sizeof(tCamp),1,pCamp);
		
		Apagar(0);
		gotoxy(5,14);	printf("Alteracao concluida!");
	}
	else
	{
		Apagar(0);
		gotoxy(5,14);	printf("Campeonato nao encontrado!");
	}
		
	getch();
	fclose(pCamp);
}

void alterarJogador()
{
	FILE *pJogador = fopen("aJogador.dat","rb+");
	tJogador jogador;
	int pos, i, j;
	
	gotoxy(5,20);	printf("Digite o codigo do participante do campeonato a ser alterado: ");
	scanf("%d", &jogador.codP);
	
	gotoxy(5,21);	printf("Digite o codigo do campeonato em que ele esta: ");
	scanf("%d", &jogador.codC);
	
	pos = buscaJogadorexaust(pJogador, jogador.codP , jogador.codC);
	
	if(pos != -1)
	{
		fseek(pJogador,pos,0);
		fread(&jogador,sizeof(tJogador),1,pJogador);
		Apagar(0);
		gotoxy(5,12);	printf("Nome atual: %s",jogador.nick);
		
		gotoxy(5,22);	printf("Digite novo nome: ");
		fflush(stdin);
		gets(jogador.nick);
		
		i = BuscaJogadorsent(pJogador, jogador.nick, jogador.codC);
		
		if(i == -1)
		{
			fseek(pJogador, pos, 0);
			fwrite(&jogador, sizeof(tJogador), 1, pJogador);
			
			Apagar(0);
			gotoxy(5,12);	printf("%d - %d - %s", jogador.codC, jogador.codP, jogador.nick);
			gotoxy(5,14);	printf("Alteracao concluida!");
			getch();
		}
		else
		{
			Apagar(0);
			gotoxy(5,14);	printf("Jogador ja cadastrado!");
			getch();
		}
	}
	else
	{
		Apagar(0);
		gotoxy(5,14);	printf("Jogador nao cadastrado em campeonato!");
		getch();
	}
	
	fclose(pJogador);
}

void ConsultaJogo()
{
	FILE * pJogo = fopen("aJogo.dat","rb");
	tJogo jogo;
	int pos;
	
	gotoxy(5,20);	printf("Digite codigo do jogo: ");
	scanf("%d", &jogo.cod);
	
	pos = buscaJogoexaust(pJogo, jogo.cod);
	
	if(pos != -1)
	{
		fseek(pJogo, pos, 0);
		fread(&jogo, sizeof(tJogo), 1, pJogo);
		
		Apagar(0);
		gotoxy(5,12);	printf("%d - %s", jogo.cod, jogo.desc);
		getch();
	}
	else
	{
		Apagar(0);
		gotoxy(5,14);	printf("Jogo nao cadastrado!");
		getch();
	}
	
	fclose(pJogo);
}

void ConsultaPart()
{
	FILE * pPart = fopen("aPart.dat","rb");
	tPart part;
	int pos;
	
	gotoxy(5,20);	printf("Digite codigo do participante: ");
	scanf("%d", &part.cod);
	
	pos = buscaPartexaust(pPart, part.cod);
	
	if(pos != -1)
	{
		fseek(pPart, pos, 0);
		fread(&part, sizeof(tPart), 1, pPart);
		
		Apagar(0);
		gotoxy(5,12);	printf("%d - %s", part.cod, part.desc);
		getch();
	}
	else
	{
		Apagar(0);
		gotoxy(5,14);	printf("Participante nao cadastrado!");
		getch();
	}
	
	fclose(pPart);
}

void ConsultaCamp()
{
	FILE * pCamp = fopen("aCamp.dat","rb");
	tCamp camp;
	int pos;
	
	gotoxy(5,20);	printf("Digite codigo do campeonato: ");
	scanf("%d", &camp.codC);
	
	pos = buscaCampexaust(pCamp, camp.codC);
	
	if(pos != -1)
	{
		fseek(pCamp, pos, 0);
		fread(&camp, sizeof(tCamp), 1, pCamp);
		
		Apagar(0);
		gotoxy(5,12);	printf("%d - %s - %d - %s",camp.codC, camp.titulo, camp.ano, camp.responsavel);
		gotoxy(5,13);	printf("%s", camp.desc);
		getch();
	}
	else
	{
		Apagar(0);
		gotoxy(5,14);	printf("Campeonato nao cadastrado!");
		getch();
	}
	
	fclose(pCamp);
}

void ConsultaJogador()
{
	FILE * pJogador = fopen("aJogador.dat","rb");
	tJogador jogador;
	int pos;
	
	gotoxy(5,20);	printf("Digite o codigo do participante do campeonato: ");
	scanf("%d", &jogador.codP);
	
	gotoxy(5,21);	printf("Digite o codigo do campeonato em que ele esta: ");
	scanf("%d", &jogador.codC);
	
	pos = buscaJogadorexaust(pJogador, jogador.codP, jogador.codC);
	
	if(pos != -1)
	{
		fseek(pJogador, pos, 0);
		fread(&jogador, sizeof(tJogador), 1, pJogador);
		
		Apagar(0);
		gotoxy(5,12);	printf("%d - %d - %s", jogador.codC, jogador.codP, jogador.nick);
		getch();
	}
	else
	{
		Apagar(0);
		gotoxy(5,14);	printf("Jogador nao cadastrado em campeonato!");
		getch();
	}
	
	fclose(pJogador);
}

void rel1()
{
	FILE *pJogo = fopen("aJogo.dat", "rb");
	FILE *pPart	= fopen("aPart.dat", "rb");
	FILE *pCamp	= fopen("aCamp.dat", "rb");
	FILE *pJogador = fopen("aJogador.dat", "rb");

	tJogo jogo;
	tPart part;
	tCamp camp;
	tJogador jogador;
	int pos,cont,soma=0, i=6;
	char nome[50];
	
	gotoxy(5,20);	printf("Digite o nome do participante desejado:");
	fflush(stdin);
	gets(nome);
	pos = BuscaPartsent(pPart,nome);
	if(pos != -1)
	{
		Apagar(0);
		fseek(pPart,pos,0);
		fread(&part,sizeof(tPart),1,pPart);
		gotoxy(5,i);	printf("Jogador selecionado: %s",part.desc);	i++;
		gotoxy(5,i);	printf("----------------------------------------------------------------------------------");	i++;

		rewind(pJogo);
		fread(&jogo,sizeof(tJogo),1,pJogo);
		while(!feof(pJogo))
		{
			cont = 0;
			rewind(pCamp);
			fread(&camp,sizeof(tCamp),1,pCamp);
			while(!feof(pCamp))
			{
				if(jogo.cod == camp.codJ)
				{
					pos = buscaJogadorexaust(pJogador,part.cod,camp.codC);
					if(pos != -1)
					{
						fseek(pJogador,pos,0);
						fread(&jogador,sizeof(tJogador),1,pJogador);
						
						if(cont == 0)
						{
							gotoxy(5,i);	printf("-> Tipo de Jogo: %s",jogo.desc);	i++;
						}
							
						
						gotoxy(5,i);	printf("%s - Responsavel: %s(%d) - Nick:%s",camp.titulo,camp.responsavel,camp.ano,jogador.nick);	i++;
						cont++;
					}
				}
				
				fread(&camp,sizeof(tCamp),1,pCamp);
			}
			
			if(cont > 0)
			{
				gotoxy(5,i);	printf("Total de Campeonatos: %d",cont);	i++;
				gotoxy(5,i);	printf("----------------------------------------------------------------------------------");	i++;
			}
			soma += cont;
			
			fread(&jogo,sizeof(tJogo),1,pJogo);
		}
		gotoxy(5,26);	printf("Total de Campeonatos do Participante: %d",soma);
	}
	else
	{
		gotoxy(5,14);	printf("Jogador nao encontrado");
	}
		
	
	fclose(pJogo);
	fclose(pPart);
	fclose(pCamp);
	fclose(pJogador);
	getch();
}

void rel2()
{
	FILE *pJogo = fopen("aJogo.dat", "rb");
	FILE *pPart	= fopen("aPart.dat", "rb");
	FILE *pCamp	= fopen("aCamp.dat", "rb");
	FILE *pJogador = fopen("aJogador.dat", "rb");

	tJogo jogo;
	tPart part;
	tCamp camp;
	tJogador jogador;
	int pos, i;
	char nome[50];
	
	gotoxy(5,20);	printf("Digite o nome do campeonato desejado:");
	fflush(stdin);
	gets(nome);
	pos = BuscaCampsent(pCamp,nome);
	if(pos != -1)
	{
		Apagar(0);
		fseek(pCamp,pos,0);
		fread(&camp,sizeof(tCamp),1,pCamp);
		gotoxy(5,6);	printf("%s",camp.titulo);
		
		pos = buscaJogoexaust(pJogo,camp.codJ);
		fseek(pJogo,pos,0);
		fread(&jogo,sizeof(tJogo),1,pJogo);
		
		gotoxy(5,7);	printf("Responsavel: %s - %d - %s",camp.responsavel,camp.ano,jogo.desc);
		gotoxy(5,9);	printf("Descricao:");
		gotoxy(5,10);	printf("%s",camp.desc);
		gotoxy(5,11);	printf("Participantes(em ordem alfabetica):");
		
		i=12;
		ordenarPartselection();
		fread(&part,sizeof(tPart),1,pPart);
		while(!feof(pPart))
		{
			pos = buscaJogadorexaust(pJogador,part.cod,camp.codC);
			if(pos != -1)
			{
				gotoxy(5,i);	printf("  %d.%s", i-11, part.desc);	i++;
			}
			fread(&part,sizeof(tPart),1,pPart);
		}
	}
	else
	{
		gotoxy(5,14);	printf("Campeonato nao encontrado!");
	}
		
	fclose(pJogo);
	fclose(pPart);
	fclose(pCamp);
	fclose(pJogador);
	getch();
}


void exibirJogo()
{
	FILE *pJogo = fopen("aJogo.dat","rb");
	tJogo jogo;
	int i;
	
	Apagar(1);
	gotoxy(4,3);	printf("<[  Lista Jogo  ]>");
	i=6;
	fread(&jogo, sizeof(tJogo), 1, pJogo);
	while(!feof(pJogo))
	{
		if(jogo.status == 'A')
		{
			gotoxy(5,i);	printf("%d - %s", jogo.cod, jogo.desc);	i++;
		}
		fread(&jogo, sizeof(tJogo), 1, pJogo);
	}
	fclose(pJogo);
	getch();
}

void exibirCamp()
{
	FILE *pCamp = fopen("aCamp.dat","rb");
	tCamp camp;
	int i;
	
	Apagar(1);
	gotoxy(4,3);	printf("<[  Lista Campeonato  ]>");
	i=6;
	fread(&camp, sizeof(tCamp), 1, pCamp);
	while(!feof(pCamp))
	{
		if(camp.status == 'A')
		{
			gotoxy(5,i);	printf("%d - %s - %d - %s",camp.codC, camp.titulo, camp.ano, camp.responsavel);	i++;
			gotoxy(5,i);	printf("%s", camp.desc);	i+=2;	
		}
		fread(&camp, sizeof(tCamp), 1, pCamp);
	}
	fclose(pCamp);
	getch();
}

void exibirPart()
{
	FILE *pPart = fopen("aPart.dat","rb");
	tPart part;
	int i;
	
	Apagar(1);
	gotoxy(4,3);	printf("<[  Lista Participante  ]>");
	i=6;
	fread(&part, sizeof(tPart), 1, pPart);
	while(!feof(pPart))
	{
		if(part.status == 'A')
		{
			gotoxy(5,i);	printf("%d - %s", part.cod, part.desc);	i++;
		}
		fread(&part, sizeof(tPart), 1, pPart);
	}
	fclose(pPart);
	getch();
}

void exibirJogador()
{
	FILE *pJogador = fopen("aJogador.dat","rb");
	tJogador jogador;
	int i;
	
	Apagar(1);
	gotoxy(4,3);	printf("<[  Lista Jogador  ]>");
	i=6;
	fread(&jogador, sizeof(tJogador), 1, pJogador);
	while(!feof(pJogador))
	{
		if(jogador.status == 'A')
		{
			gotoxy(5,i);	printf("%d - %d - %s", jogador.codC, jogador.codP, jogador.nick);	i++;
		}
		fread(&jogador, sizeof(tJogador), 1, pJogador);
	}
	fclose(pJogador);
	getch();
}


//_________________________________________________________
//*************************MAIN****************************
//¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
int main()
{
	char r;
	
	fInicializar();
	ordenarCampselection();
	Bordarear(0);
	do
	{
		Apagar(1);
		gotoxy(4,3);	printf("<[  Menu  ]>");
		r = menu();
		
		switch(r)
		{
			case 'A':	//Cadastros
				do
				{
					Apagar(1);
					gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  ]>");
					r = menuTipos();
					
					switch(r)
					{
						case 'A':	//Jogo
							do
							{
								Apagar(1);
								gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Jogo  ]>");
								r = menuCadastros();
								
								switch(r)
								{
									case 'A':	//Cadastrar
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Jogo  >>  Cadastrar  ]>");
										CadastrarJogo();
										break;
										
									case 'B':	//Alterar
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Jogo  >>  Alterar ]>");
										alterarJogo();
										break;
										
									case 'C':	//Excluir
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Jogo  >>  Excluir  ]>");
										exclusaologicaJogo();
										exclusaofisicaJogo();
										break;
										
									case 'D':	//Consultar
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Jogo  >>  Consultar  ]>");
										ConsultaJogo();
										break;
								}
							}while(r !=27);
							r = 'X';
							break;
							
						case 'B':	//Participantes
							do
							{
								Apagar(1);
								gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Participantes  ]>");
								r = menuCadastros();
								
								switch(r)
								{
									case 'A':	//Cadastrar
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Participantes  >>  Cadastrar  ]>");
										CadastrarPart();
										break;
										
									case 'B':	//Alterar
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Participantes  >>  Alterar  ]>");
										alterarPart();
										break;
										
									case 'C':	//Excluir
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Participantes  >>  Excluir  ]>");
										exclusaologicaParticipante();
										exclusaofisicaPart();
										break;
										
									case 'D':	//Consultar
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Participantes  >>  Consultar  ]>");
										ConsultaPart();
										break;
								}
							}while(r !=27);
							r = 'X';
							break;
							
						case 'C':	//Campeonato
							do
							{
								Apagar(1);
								gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Campeonato  ]>");
								r = menuCadastros();
								
								switch(r)
								{
									case 'A':	//Cadastrar
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Campeonato  >>  Cadastrar  ]>");
										CadastrarCamp();
										break;
										
									case 'B':	//Alterar
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Campeonato  >>  Alterar ]>");
										alterarCamp();
										break;
										
									case 'C':	//Excluir
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Campeonato  >>  Excluir  ]>");
										exclusaologicaCampeonato();
										exclusaofisicaCamp();
										break;
										
									case 'D':	//Consultar
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Campeonato  >>  Consultar  ]>");
										ConsultaCamp();
										break;
								}
							}while(r !=27);
							r = 'X';
							break;
							
						case 'D':	//Jogador
							do
							{
								Apagar(1);
								gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Jogador  ]>");
								r = menuCadastros();
								
								switch(r)
								{
									case 'A':	//Cadastrar
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Jogador  >>  Cadastrar  ]>");
										CadastrarJogador();
										break;
										
									case 'B':	//Alterar
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Jogador  >>  Alterar  ]>");
										alterarJogador();
										break;
										
									case 'C':	//Excluir
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Jogador  >>  Excluir  ]>");
										exclusaologicaJogador();
										exclusaofisicaJogador();
										break;
										
									case 'D':	//Consultar
										gotoxy(4,3);	printf("<[  Menu  >>  Cadastros  >>  Jogador  >>  Consultar  ]>");
										ConsultaJogador();
										break;
								}
							}while(r !=27);
							r = 'X';
							break;
					}
				}while(r!=27);
				r = 'X';
				break;
				
			case 'B':	//Relatorios
				do
				{
					Apagar(1);
					gotoxy(4,3);	printf("<[  Menu  >>  Relatorios  ]>");
					r = menuRelatorios();
					
					switch(r)
					{
						case 'A':	//RelatorioGeral
							do
							{
								Apagar(1);
								gotoxy(4,3);	printf("<[  Menu  >>  Relatorios  >>  Relatorio Geral  ]>");
								r = menuTipos();
								
								switch(r)
								{
									case 'A':	//Jogo
										gotoxy(4,3);	printf("<[  Menu  >>  Relatorios  >>  Relatorio Geral  >>  Jogo  ]>");
										exibirJogo();
										break;
										
									case 'B':	//Participante
										gotoxy(4,3);	printf("<[  Menu  >>  Relatorios  >>  Relatorio Geral  >>  Participante  ]>");
										exibirPart();
										break;
										
									case 'C':	//Campeonato
										ordenarCampbubble();
										gotoxy(4,3);	printf("<[  Menu  >>  Relatorios  >>  Relatorio Geral  >>  Campeonato  ]>");
										exibirCamp();
										ordenarCampselection();
										break;
										
									case 'D':	//Jogador
										gotoxy(4,3);	printf("<[  Menu  >>  Relatorios  >>  Relatorio Geral  >>  Jogador  ]>");
										exibirJogador();
										break;
								}
							}while(r != 27);
							r = 'X';	
							break;
							
						case 'B':	//Relatorio1
							gotoxy(4,3);	printf("<[  Menu  >>  Relatorios  >>  Relatorio1  ]>");
							rel1();
							break;
						
						case 'C':	//Relatorio2
							gotoxy(4,3);	printf("<[  Menu  >>  Relatorios  >>  Relatorio2  ]>");
							rel2();
							break;
								
					}
				}while(r!=27);
				r = 'X';
				break;
		}
	}while(r!=27);
	Apagar(1);
	gotoxy(4,3);	printf("<[  Excluindo...  ]>");
	exclusaofisica();
	getch();
	
	gotoxy(4,3);	printf("<[  Lista Jogo  ]>");
	exibirJogo();
	gotoxy(4,3);	printf("<[  Lista Participante  ]>");
	exibirPart();
	gotoxy(4,3);	printf("<[  Lista Campeonato  ]>");
	ordenarCampbubble();
	exibirCamp();
	gotoxy(4,3);	printf("<[  Lista Jogador  ]>");
	exibirJogador();
	
	Apagar(1);
	gotoxy(4,3);	printf("<[  Finalizando...  ]>");
	getch();
	
	return 0;
}
