#include<stdio.h>
#include<iniparser.h>

int main(int argc, char** argv){
	dictionary * ini = NULL;
	char       * ini_name = *(argv+1);

	ini = iniparser_load(ini_name);

	printf("Valor leido: %s\n", iniparser_getstring(ini,"SECCION_1:clave_string",NULL));
	printf("Valor leido: %d\n", iniparser_getint(ini,"SECCION_2:clave_num2",0));

	iniparser_dump(ini, stdout);
	printf("Cantidad de secciones: %d\n",iniparser_getnsec(ini));
	printf("Cantidad de en la SECCION_2: %d\n",iniparser_getsecnkeys(ini,"SECCION_2"));

	iniparser_freedict(ini);

	return 0;
}
