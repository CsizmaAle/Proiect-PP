# Proiect de Programare/ C++

>**Last update:** June 2025  

## Sistem catalog online

> **Nota:** Acest proiect are scop educativ si reprezinta o solutie originala. 

### I. Enunț 
Sistem catalog online  
Studentul 1 se ocupă de gestionarea notelor:
- adaugă, șterge note
- adaugă absențe

Studentul 2 se ocupă de gestionarea elevilor:
- adaugă, șterge elevi din catalog
- poate motiva absențele

### II. Structura datelor folosite de echipă  
Vom folosi clasele:  
●	Data: int zi, int luna, int an  
●	Nota: int nota, Data data  
●	Materie: string materie, Nota note[], Absenta absente[]  
●	Absenta: Data data, bool motivat  
●	Student: string nume_elev, Materie informatii_student[], int numar_materii  

### III. Structura fișierelor:  
catalog.txt  
-	fișier în care vom stoca detaliile catalogului pentru fiecare elev
  ```
  <numar_elevi>  
  <numar_materii>  
  <nume_elev1>  
  <materie1>  
  <nota1> <zi1> <luna1> <an1> <nota2> <zi2> <luna2> <an2> …  
  <zi1> <luna1> <an1> <1/0> <zi2> <luna2> <an2> <1/0> …  
  <materie 2>   
  …
```

### VI.Interacțiunea cu executabilele  
Aplicația 1 va expune următoarele posibilități:  
```./app_1.exe adaugare_nota <nume_elev> <materie> <nota> <data>  ```
-	pentru adăugarea unei note  

```./app_1.exe stergere_nota <nume_elev> <materie> <nota> <data>  ```
-	pentru ștergerea notei
  
```./app_1.exe adaugare_absenta <nume_elev> <materie> <data>  ```
-	pntru adăugarea unei absențe  

```./app_1.exe vizualizare_elev <nume>  ```
-	pentru a vizualiza materiile, notele și absențele unui anumit elev  

Aplicația 2 va expune următoarele posibilități:  
```./app_2.exe adaugare_elev  <nume_elev>   ```
-	pentru adăugarea unui elev  

```./app_2.exe stergere_elev  <nume_elev>   ```
-	pentru ștergerea unui elev  

```./app_2.exe motivare_absenta  <nume_elev> <materie> <data>  ```
-	pentru motivarea absenței unui elev  

```./app_2.exe vizualizare_catalog  ```
-	pentru a vizualiza întregul catalog cu situațiile tuturor elevilor  




