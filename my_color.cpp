// test_couleur.cpp : Seuille une image en 3 ou 4 niveau de gris

#include <stdio.h>
#include "image_ppm.h"
#include <string>

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];

    char cNomImgR[250];
    char cNomImgV[250];
    char cNomImgB[250];
  int nH, nW, nTaille, S_R, nb_seuil, S_V, S_B,nR, nG, nB;
  
  if (argc != 6) 
     {
       printf("Usage: ImageIn.ppm ImageOut.ppm S_R S_V S_B\n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);
   sscanf (argv[3],"%d",&S_R);
   sscanf (argv[4],"%d",&S_V);
   sscanf (argv[5],"%d",&S_B);


    OCTET *ImgIn, *ImgOut;
   
   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   int nTaille3 = nTaille * 3;
   allocation_tableau(ImgIn, OCTET, nTaille3);
   lire_image_ppm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille3);
	
   for (int i=0; i < nTaille3; i+=3)
     {
       nR = ImgIn[i];
       nG = ImgIn[i+1];
       nB = ImgIn[i+2];
       if (nR < S_R) ImgOut[i]=0; else ImgOut[i]=255;
       if (nG < S_V) ImgOut[i+1]=0; else ImgOut[i+1]=255; 
       if (nB < S_B) ImgOut[i+2]=0; else ImgOut[i+2]=255;
     }

   ecrire_image_ppm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
