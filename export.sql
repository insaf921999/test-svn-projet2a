--------------------------------------------------------
--  Fichier cr�� - lundi-juin-15-2020   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Sequence CONGE_SEQ
--------------------------------------------------------

   CREATE SEQUENCE  "INSAF"."CONGE_SEQ"  MINVALUE 1 MAXVALUE 999999999999999999999999999 INCREMENT BY 1 START WITH 1 CACHE 20 NOORDER  NOCYCLE ;
--------------------------------------------------------
--  DDL for Table ABONNEMENTS
--------------------------------------------------------

  CREATE TABLE "INSAF"."ABONNEMENTS" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"NUMPLACE" NUMBER, 
	"DATENAISS" VARCHAR2(20 BYTE), 
	"DATEDEB" VARCHAR2(20 BYTE), 
	"DATEFIN" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table AGENT
--------------------------------------------------------

  CREATE TABLE "INSAF"."AGENT" 
   (	"ID" VARCHAR2(20 BYTE), 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"ROLE" VARCHAR2(20 BYTE), 
	"DATED" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CARTESOLDE
--------------------------------------------------------

  CREATE TABLE "INSAF"."CARTESOLDE" 
   (	"ID_COMPTES" NUMBER, 
	"MONTANT" NUMBER, 
	"DATE_OUVERTURE" VARCHAR2(20 BYTE), 
	"ID_CLIENT" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CLIENT
--------------------------------------------------------

  CREATE TABLE "INSAF"."CLIENT" 
   (	"ID_CLIENT" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table COLI
--------------------------------------------------------

  CREATE TABLE "INSAF"."COLI" 
   (	"REFERENCE" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"IDCLIENTDEST" VARCHAR2(20 BYTE), 
	"POIDS" VARCHAR2(20 BYTE), 
	"NBPIECE" VARCHAR2(20 BYTE), 
	"ETAT" VARCHAR2(20 BYTE), 
	"PAIEMENT" VARCHAR2(20 BYTE), 
	"MONTANT" VARCHAR2(20 BYTE), 
	"ADRESSEEXP" VARCHAR2(20 BYTE), 
	"ADRESSEDEST" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CONGE
--------------------------------------------------------

  CREATE TABLE "INSAF"."CONGE" 
   (	"NOM" VARCHAR2(20 BYTE), 
	"ENCONGE" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE), 
	"DATED" VARCHAR2(20 BYTE), 
	"DATEF" VARCHAR2(20 BYTE), 
	"ID" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table COURRIER
--------------------------------------------------------

  CREATE TABLE "INSAF"."COURRIER" 
   (	"REF3" NUMBER, 
	"NBPIECEJ" VARCHAR2(20 BYTE), 
	"NOM3" VARCHAR2(20 BYTE), 
	"IDCLIENTDEST3" VARCHAR2(20 BYTE), 
	"ETAT3" VARCHAR2(20 BYTE), 
	"PAIEMENT3" VARCHAR2(20 BYTE), 
	"MONTANT3" VARCHAR2(20 BYTE), 
	"ADRESSEE" VARCHAR2(20 BYTE), 
	"ADRESSED" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table ETUDIANT
--------------------------------------------------------

  CREATE TABLE "INSAF"."ETUDIANT" 
   (	"ID" NUMBER(*,0), 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table LIVRAISON
--------------------------------------------------------

  CREATE TABLE "INSAF"."LIVRAISON" 
   (	"IDCLIENT" NUMBER(*,0), 
	"CATEGORIE" VARCHAR2(20 BYTE), 
	"ETATLIV" VARCHAR2(20 BYTE), 
	"TRANSPORTEUR" VARCHAR2(20 BYTE), 
	"PAIEMENTLIV" VARCHAR2(20 BYTE), 
	"DATE_LIV" VARCHAR2(20 BYTE), 
	"ADRESSE_DEST" VARCHAR2(20 BYTE), 
	"ADRESSE_EXP" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MORAL
--------------------------------------------------------

  CREATE TABLE "INSAF"."MORAL" 
   (	"RIB" NUMBER, 
	"MATRICULE" NUMBER, 
	"NOM_ENTREPRISE" VARCHAR2(20 BYTE), 
	"ID_CLIENT" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PARKING
--------------------------------------------------------

  CREATE TABLE "INSAF"."PARKING" 
   (	"ID" NUMBER, 
	"PRENOM" VARCHAR2(20 BYTE), 
	"NBRPLACE" NUMBER, 
	"NBRETAGE" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PHYSIQUE
--------------------------------------------------------

  CREATE TABLE "INSAF"."PHYSIQUE" 
   (	"CIN" VARCHAR2(20 BYTE), 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"DATE_NAISSANCE" VARCHAR2(20 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"EMAIL" VARCHAR2(20 BYTE), 
	"ID_CLIENT" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into INSAF.ABONNEMENTS
SET DEFINE OFF;
Insert into INSAF.ABONNEMENTS (ID,NOM,PRENOM,NUMPLACE,DATENAISS,DATEDEB,DATEFIN) values ('5','bb','yy','55','01-JAN-00','01-JAN-00','01-JAN-00');
REM INSERTING into INSAF.AGENT
SET DEFINE OFF;
Insert into INSAF.AGENT (ID,NOM,PRENOM,ROLE,DATED) values ('15','ppp','xxx','sous chef','01/01/2000');
Insert into INSAF.AGENT (ID,NOM,PRENOM,ROLE,DATED) values ('55','haha','goo','chef','02/01/2000');
REM INSERTING into INSAF.CARTESOLDE
SET DEFINE OFF;
Insert into INSAF.CARTESOLDE (ID_COMPTES,MONTANT,DATE_OUVERTURE,ID_CLIENT) values ('55','22','15-JUN-20','20');
Insert into INSAF.CARTESOLDE (ID_COMPTES,MONTANT,DATE_OUVERTURE,ID_CLIENT) values ('55','405','15-JUN-20','20');
Insert into INSAF.CARTESOLDE (ID_COMPTES,MONTANT,DATE_OUVERTURE,ID_CLIENT) values ('88','22','15-JUN-20','20');
REM INSERTING into INSAF.CLIENT
SET DEFINE OFF;
Insert into INSAF.CLIENT (ID_CLIENT,TYPE) values ('3','aa');
Insert into INSAF.CLIENT (ID_CLIENT,TYPE) values ('6','cc');
Insert into INSAF.CLIENT (ID_CLIENT,TYPE) values ('20','bb');
REM INSERTING into INSAF.COLI
SET DEFINE OFF;
Insert into INSAF.COLI (REFERENCE,NOM,IDCLIENTDEST,POIDS,NBPIECE,ETAT,PAIEMENT,MONTANT,ADRESSEEXP,ADRESSEDEST) values ('22','217485','2355','11','22','en attente','par carte','22','a','zz');
Insert into INSAF.COLI (REFERENCE,NOM,IDCLIENTDEST,POIDS,NBPIECE,ETAT,PAIEMENT,MONTANT,ADRESSEEXP,ADRESSEDEST) values ('55','11abc','7','1','20402','en attente','par carte','22','aa','zzz');
Insert into INSAF.COLI (REFERENCE,NOM,IDCLIENTDEST,POIDS,NBPIECE,ETAT,PAIEMENT,MONTANT,ADRESSEEXP,ADRESSEDEST) values ('90','181JFT2762','10','4','6','en attente','en especes','200','tunis','sousse');
Insert into INSAF.COLI (REFERENCE,NOM,IDCLIENTDEST,POIDS,NBPIECE,ETAT,PAIEMENT,MONTANT,ADRESSEEXP,ADRESSEDEST) values ('77','181JFT2762','44','1','3','en attente','par carte','44','55','22');
REM INSERTING into INSAF.CONGE
SET DEFINE OFF;
Insert into INSAF.CONGE (NOM,ENCONGE,TYPE,DATED,DATEF,ID) values ('aa','oui','jour ferier','19/05/2020','22/05/2020','1');
Insert into INSAF.CONGE (NOM,ENCONGE,TYPE,DATED,DATEF,ID) values ('bb','oui','maladie','25/05/2020','25/05/2020','4');
REM INSERTING into INSAF.COURRIER
SET DEFINE OFF;
Insert into INSAF.COURRIER (REF3,NBPIECEJ,NOM3,IDCLIENTDEST3,ETAT3,PAIEMENT3,MONTANT3,ADRESSEE,ADRESSED) values ('24','44','1234','27','en attente','en especes','77','tunis','bizerte');
Insert into INSAF.COURRIER (REF3,NBPIECEJ,NOM3,IDCLIENTDEST3,ETAT3,PAIEMENT3,MONTANT3,ADRESSEE,ADRESSED) values ('8','1','181JFT2762','1','en attente','en especes','44','z','a');
Insert into INSAF.COURRIER (REF3,NBPIECEJ,NOM3,IDCLIENTDEST3,ETAT3,PAIEMENT3,MONTANT3,ADRESSEE,ADRESSED) values ('7','1','9876','7','en attente','par carte','77','a','z');
Insert into INSAF.COURRIER (REF3,NBPIECEJ,NOM3,IDCLIENTDEST3,ETAT3,PAIEMENT3,MONTANT3,ADRESSEE,ADRESSED) values ('22','2','09630801','77','en attente','en especes','666','aaa','ccc');
REM INSERTING into INSAF.ETUDIANT
SET DEFINE OFF;
Insert into INSAF.ETUDIANT (ID,NOM,PRENOM) values ('11','aa','zzz');
REM INSERTING into INSAF.LIVRAISON
SET DEFINE OFF;
Insert into INSAF.LIVRAISON (IDCLIENT,CATEGORIE,ETATLIV,TRANSPORTEUR,PAIEMENTLIV,DATE_LIV,ADRESSE_DEST,ADRESSE_EXP) values ('22','4','en cours','sarra','cash','10avril','ben arous','ariana');
Insert into INSAF.LIVRAISON (IDCLIENT,CATEGORIE,ETATLIV,TRANSPORTEUR,PAIEMENTLIV,DATE_LIV,ADRESSE_DEST,ADRESSE_EXP) values ('22','courrier','termin??','ayoub','cash','22mars','sousa','beja');
Insert into INSAF.LIVRAISON (IDCLIENT,CATEGORIE,ETATLIV,TRANSPORTEUR,PAIEMENTLIV,DATE_LIV,ADRESSE_DEST,ADRESSE_EXP) values ('3','coli','terminee','louay','cash','22fev','tunis','mahdia');
Insert into INSAF.LIVRAISON (IDCLIENT,CATEGORIE,ETATLIV,TRANSPORTEUR,PAIEMENTLIV,DATE_LIV,ADRESSE_DEST,ADRESSE_EXP) values ('181','4','en cours','zohra','cash','9avril','ben arous','ariana');
Insert into INSAF.LIVRAISON (IDCLIENT,CATEGORIE,ETATLIV,TRANSPORTEUR,PAIEMENTLIV,DATE_LIV,ADRESSE_DEST,ADRESSE_EXP) values ('22','4','en cours','Aziz','cash','20avril','ben arous','ariana');
REM INSERTING into INSAF.MORAL
SET DEFINE OFF;
Insert into INSAF.MORAL (RIB,MATRICULE,NOM_ENTREPRISE,ID_CLIENT) values ('45','75','yass','12');
Insert into INSAF.MORAL (RIB,MATRICULE,NOM_ENTREPRISE,ID_CLIENT) values ('25','36','ghost','11');
Insert into INSAF.MORAL (RIB,MATRICULE,NOM_ENTREPRISE,ID_CLIENT) values ('30','1177','insaf','66');
Insert into INSAF.MORAL (RIB,MATRICULE,NOM_ENTREPRISE,ID_CLIENT) values ('55','656','aa','55');
REM INSERTING into INSAF.PARKING
SET DEFINE OFF;
Insert into INSAF.PARKING (ID,PRENOM,NBRPLACE,NBRETAGE) values ('22','a','2','100');
Insert into INSAF.PARKING (ID,PRENOM,NBRPLACE,NBRETAGE) values ('11','mmm','12','5');
Insert into INSAF.PARKING (ID,PRENOM,NBRPLACE,NBRETAGE) values ('7','aa','2','1');
Insert into INSAF.PARKING (ID,PRENOM,NBRPLACE,NBRETAGE) values ('0',null,'0','1');
REM INSERTING into INSAF.PHYSIQUE
SET DEFINE OFF;
Insert into INSAF.PHYSIQUE (CIN,NOM,PRENOM,DATE_NAISSANCE,ADRESSE,EMAIL,ID_CLIENT) values ('20','esprit','espritn','01/01/2000','tunis','ok',null);
Insert into INSAF.PHYSIQUE (CIN,NOM,PRENOM,DATE_NAISSANCE,ADRESSE,EMAIL,ID_CLIENT) values ('19','insaf','test','01/01/2000','hamalanf','esprit',null);
Insert into INSAF.PHYSIQUE (CIN,NOM,PRENOM,DATE_NAISSANCE,ADRESSE,EMAIL,ID_CLIENT) values ('88','abc','cba','01/01/2000','kkkk','uuu',null);
Insert into INSAF.PHYSIQUE (CIN,NOM,PRENOM,DATE_NAISSANCE,ADRESSE,EMAIL,ID_CLIENT) values ('98765','done','now','01/01/2000','france','gmail',null);
Insert into INSAF.PHYSIQUE (CIN,NOM,PRENOM,DATE_NAISSANCE,ADRESSE,EMAIL,ID_CLIENT) values ('987654321','doneee','nowww','01/01/2000','franceeee','gmaillll',null);
--------------------------------------------------------
--  DDL for Index CONGE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "INSAF"."CONGE_PK" ON "INSAF"."CONGE" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index COLI_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "INSAF"."COLI_PK" ON "INSAF"."COLI" ("REFERENCE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Trigger CONGE_TRG
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "INSAF"."CONGE_TRG" 
BEFORE INSERT ON CONGE 
FOR EACH ROW 
BEGIN
  <<COLUMN_SEQUENCES>>
  BEGIN
    IF INSERTING AND :NEW.ID IS NULL THEN
      SELECT CONGE_SEQ.NEXTVAL INTO :NEW.ID FROM SYS.DUAL;
    END IF;
  END COLUMN_SEQUENCES;
END;
/
ALTER TRIGGER "INSAF"."CONGE_TRG" ENABLE;
--------------------------------------------------------
--  Constraints for Table LIVRAISON
--------------------------------------------------------

  ALTER TABLE "INSAF"."LIVRAISON" MODIFY ("IDCLIENT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table COURRIER
--------------------------------------------------------

  ALTER TABLE "INSAF"."COURRIER" MODIFY ("REF3" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table COLI
--------------------------------------------------------

  ALTER TABLE "INSAF"."COLI" ADD CONSTRAINT "COLI_PK" PRIMARY KEY ("REFERENCE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table CONGE
--------------------------------------------------------

  ALTER TABLE "INSAF"."CONGE" ADD CONSTRAINT "CONGE_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "INSAF"."CONGE" MODIFY ("ID" NOT NULL ENABLE);
