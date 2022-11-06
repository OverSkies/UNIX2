#include "FichierClient.h"

int estPresent(const char* nom)
{
  CLIENT buffer;
  int fd, rc, pos, taille, i = 0;

  if((fd = open(FICHIER_CLIENTS, O_RDONLY)) == -1)
  {
    perror("Erreur de Open()");
    return -1;
  }

  if((pos = lseek(fd, 0, SEEK_END)) == -1)
  {
    perror("Erreur de lseek() !");
    return -1;
  }

  taille = rc / sizeof(CLIENT);

  if((rc = lseek(fd, 0, SEEK_SET)) == -1)
  {
    perror("Erreur de lseek() !");
    return -1;
  }

  while(strcmp(buffer.nom, nom) != 0 && i < taille)
  {
    if((rc = read(fd, &buffer, sizeof(CLIENT))) == -1)
    {
      perror("Erreur de read() !");
      return -1;
    }
    pos++;
    i++;
  }
    

  if(strcmp(buffer.nom, nom) != 0)
  {
    pos = 0;
    printf("Pas trouve !\n\n");
  }
  else
    buffer.nom[rc] = '\0';

  close(fd);

  return pos;
}

////////////////////////////////////////////////////////////////////////////////////
int hashage(const char* motDePasse)
{
  int h, length, i;
  const char *p;

  length = strlen(motDePasse);

  for(h = 0, i = 1, p = motDePasse; i < length + 1; i++, p++)
  {
    h += (int)(*p) * i;
  }

  return h % 97;
}

////////////////////////////////////////////////////////////////////////////////////
void ajouteClient(const char* nom, const char* motDePasse)
{
  int fd, rc, h;
  CLIENT buffer;

  strcpy(buffer.nom, nom);
  buffer.h = hashage(motDePasse);

  if((fd = open(FICHIER_CLIENTS, O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1) 
    perror("Erreur de open () !");

  if((rc = write(fd, &buffer, sizeof(CLIENT))) == -1)
    perror("Erreur de write() a l'ajout !");

  close(fd);

}

////////////////////////////////////////////////////////////////////////////////////
int verifieMotDePasse(int pos, const char* motDePasse)
{
  int fd, rc;
  CLIENT verif;

  if ((fd = open(FICHIER_CLIENTS, O_RDONLY)) == -1)
  {
    perror("Erreur de open() !");
    return -1;
  }

  if ((rc = lseek(fd, pos * sizeof(CLIENT), SEEK_SET)) == -1) perror("Erreur de lseek() !");

  if((rc = read(fd, &verif, sizeof(CLIENT))) == -1) perror("Erreur de read() !");

  close(fd);

  if(verif.h == hashage(motDePasse))
  {
    return 1;
  }
  else
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////
int listeClients(CLIENT *vecteur) // le vecteur doit etre suffisamment grand
{
  int i = 0, fd, rc, taille;
  CLIENT *p = vecteur;
  CLIENT buffer;



  if((fd = open(FICHIER_CLIENTS, O_RDONLY)) == -1)
  {
    perror("Erreur de open() !");
    return -1;
  }

  if((rc = lseek(fd, 0, SEEK_END)) == -1) perror("Erreur de lseek() !");

  taille = rc / sizeof(CLIENT);

  if((rc = lseek(fd, 0, SEEK_SET)) == -1) perror("Erreur de lseek() !");

  while(i < taille && i < 100)
  {
    if((rc = read(fd, &buffer, sizeof(CLIENT))) == -1) perror("Erreur de read() !");

    strcpy(p->nom, buffer.nom);
    p->h = buffer.h;

    i++;
    p++;
  }

  close(fd);

  return taille;
}
