#include "includes/informator.h"

void  put_tittle()
{
  printf("  _____        __                           _             \n");
  printf(" |_   _|      / _|                         | |            \n");
  printf("   | |  _ __ | |_ ___  _ __ _ __ ___   __ _| |_ ___  _ __ \n");
  printf("   | | | '_ \\|  _/ _ \\| '__| '_ ` _ \\ / _` | __/ _ \\| '__|\n");
  printf("  _| |_| | | | || (_) | |  | | | | | | (_| | || (_) | |   \n");
  printf(" |_____|_| |_|_| \\___/|_|  |_| |_| |_|\\__,_|\\__\\___/|_|   \n\n");
}

void  put_pront(char **line)
{
  write(0, "¿Que quiere preguntar?: ", strlen("¿Que quiere preguntar?: "));
  get_next_line(0, line);
}

t_inform  *fill_inform(t_inform *inform)
{
  if (!(inform = malloc(sizeof(t_inform))))
    return (0);
  inform->state = 1;
  inform->step = 0;
  inform->first = 0;
  inform->second = 0;
  return (inform);
}

void  put_basics()
{
  printf("\e[33ma)\e[0m Switch\n");
  printf("\e[33mb)\e[0m Router\n");
  printf("\e[33mc)\e[0m Ingesta de datos\n");
  printf("\e[33md)\e[0m LUN\n");
  printf("\e[33me)\e[0m Computo\n");
  printf("\e[33mf)\e[0m Rack\n");
  printf("\e[33mg)\e[0m Raid\n");
  printf("\e[33mh)\e[0m NIC\n");
  printf("\e[33mi)\e[0m VNIC\n");
  printf("\e[33mj)\e[0m HBA\n");
  printf("\e[33mk)\e[0m VHBA\n");
  printf("\e[33ml)\e[0m LAN\n");
  printf("\e[33mm)\e[0m SCSI\n");
  printf("\e[33mn)\e[0m TCP/IP\n");
  printf("\e[33mo)\e[0m Modelo OSI\n");
  printf("\e[33mback\e[0m\n");
  printf("\e[33mexit\e[0m\n");
}

void  put_sistems()
{
  printf("\e[33ma)\e[0m PC\n");
  printf("\e[33mb)\e[0m VPC\n");
  printf("\e[33mc)\e[0m Server Pools\n");
  printf("\e[33md)\e[0m CIMC mounted\n");
  printf("\e[33me)\e[0m IPMI\n");
  printf("\e[33mf)\e[0m KVM\n");
  printf("\e[33mback\e[0m\n");
  printf("\e[33mexit\e[0m\n");
}

void  put_red()
{
  printf("\e[33ma)\e[0m Red SAN\n");
  printf("\e[33mb)\e[0m Fiber Channel\n");
  printf("\e[33mc)\e[0m iSCSI\n");
  printf("\e[33mback\e[0m\n");
  printf("\e[33mexit\e[0m\n");
}

void  put_cisco()
{
  printf("\e[33ma)\e[0m Flexpod\n");
  printf("\e[33mb)\e[0m ExpressPod\n");
  printf("\e[33mc)\e[0m Blade Server\n");
  printf("\e[33md)\e[0m Fabric Interconnect\n");
  printf("\e[33mback\e[0m\n");
  printf("\e[33mexit\e[0m\n");
}

void  put_softw_manager()
{
  printf("\e[33ma)\e[0m UCMS\n");
  printf("\e[33mb)\e[0m Scrub polity\n");
  printf("\e[33mback\e[0m\n");
  printf("\e[33mexit\e[0m\n");
}

void  put_first()
{
  printf("\e[33ma)\e[0m Basic\n");
  printf("\e[33mb)\e[0m Sistemas\n");
  printf("\e[33mc)\e[0m Red\n");
  printf("\e[33md)\e[0m Cisco\n");
  printf("\e[33me)\e[0m Software/Manager\n");
  printf("\e[33mexit\e[0m\n");
}

void  put_second(t_inform *inform)
{
  if (inform->first == 'a')
    put_basics();
  else if (inform->first == 'b')
    put_sistems();
  else if (inform->first == 'c')
    put_red();
  else if (inform->first == 'd')
    put_cisco();
  else if (inform->first == 'e')
    put_softw_manager();
}

void  put_posibilities(t_inform *inform)
{
  if (inform->step == 0)
    put_first();
  if (inform->step == 1)
    put_second(inform);
  write(0, "\n", 1);
}

void  execute_first(t_inform *inform)
{
  if (!strcmp(inform->line, "a"))
    inform->first = 'a';
  else if (!strcmp(inform->line, "b"))
    inform->first = 'b';
  else if (!strcmp(inform->line, "c"))
    inform->first = 'c';
  else if (!strcmp(inform->line, "d"))
    inform->first = 'd';
  else if (!strcmp(inform->line, "e"))
    inform->first = 'e';
  else
  {
    inform->line = 0;
    inform->step--;
  }
  inform->step++;
}

void  execute_second_a(t_inform *inform)
{
  if (!strcmp(inform->line, "a"))
    inform->answer = "\e[4;33mSwitch:\e[0m o conmutador, es un dispositivo de interconexion de dispositivos, creando una red.\n";
  else if(!strcmp(inform->line, "b"))
    inform->answer =  "\e[4;33mRouter:\e[0m Conecta diferentes redes entre si.\n";
  else if(!strcmp(inform->line, "c"))
    inform->answer =  "\e[4;33mIngesta de datos:\e[0m Es el proceso por el cual se introducen datos de diferentes fuentes dentro de un sistema de almacenamiento de datos.\n";
  else if(!strcmp(inform->line, "d"))
    inform->answer =  "\e[4;33mLUN:\e[0m Es una direccion para una unidad de disco curo y por extension, el disco en si mismo. Es una forma de diferenciar unidades de disco undividuales dentro de un bus SCSI.\n";
  else if(!strcmp(inform->line, "e"))
    inform->answer =  "\e[4;33mComputo:\e[0m Los recursos disponibles.\n";
  else if(!strcmp(inform->line, "f"))
    inform->answer =  "\e[4;33mRack:\e[0m Bastidor, donde se encuentran los servidores, switches, etc.\n";
  else if(!strcmp(inform->line, "g"))
    inform->answer =  "\e[4;33mRaid:\e[0m Es un grupo redundante de discos independientes, hace referencia a un sistema de almacenamiento de datos que utiliza multiples unidades.\n";
  else if(!strcmp(inform->line, "h"))
    inform->answer =  "\e[4;33mNIC:\e[0m Tarjeta de red.\n";
  else if(!strcmp(inform->line, "i"))
    inform->answer =  "\e[4;33mVNIC:\e[0m Tarjeta de red virtual.\n";
  else if(!strcmp(inform->line, "j"))
    inform->answer =  "\e[4;33mHBA:\e[0m Host Bus Adapter: Tarjeta de fiberChannel.\n";
  else if(!strcmp(inform->line, "k"))
    inform->answer =  "\e[4;33mVHBA:\e[0m Virtual Host Bus Adapter: Tarjeta virtual de fiberChannel.\n";
  else if(!strcmp(inform->line, "l"))
    inform->answer =  "\e[4;33mLAN:\e[0m Local Area Network.\n";
  else if(!strcmp(inform->line, "m"))
    inform->answer =  "\e[4;33mSCSI:\e[0m Es una interfaz de transferencia de datos en serie. Permite leer y almacenar grandes cantitdades de informaciona grandes velocidades por medio de pequeños electroimanes.\n";
  else if(!strcmp(inform->line, "n"))
    inform->answer =  "\e[4;33mTCP/IP:\e[0m (Transmision Control Protocol) Es una descripcion de protocolos de red.\n";
  else if(!strcmp(inform->line, "o"))
    inform->answer =  "\e[4;33mModelo OSI:\e[0m (Capa->Dato) Fisico->Bits Enlace->Frames Red->Packets Transporte->Segments Sesion->Data Presentacion->Data Aplicacion->Data.\n";
  else
    inform->line = 0;
}

void  execute_second_b(t_inform *inform)
{
  if (!strcmp(inform->line, "a"))
    inform->answer = "\e[4;33mPC:\e[0m (Port Channel) Unifica 2 puertos en uno teniendo el doble de ancho de banda.\n";
  else if(!strcmp(inform->line, "b"))
    inform->answer =  "\e[4;33mVPC:\e[0m (Virtual Port-Channel) Conecta 2 switches Cisco, para que, a nivel logico se visualize como uno solo.\n";
  else if(!strcmp(inform->line, "c"))
    inform->answer =  "\e[4;33mServer Pools:\e[0m Es logicamente una region autonoma que contiene uno o mas ervidore fisicos.\n";
  else if(!strcmp(inform->line, "d"))
    inform->answer =  "\e[4;33mCIMS mounted:\e[0m Para montar CD/DVD´s des de un fichero remoto.\n";
  else if(!strcmp(inform->line, "e"))
    inform->answer =  "\e[4;33mIPMI:\e[0m Proporciona monitoreo y gestion del sistema host.\n";
  else if(!strcmp(inform->line, "f"))
    inform->answer =  "\e[4;33mKVM:\e[0m Kernel-based Virtual Machine: Es una solucion para implementar virtualizacion completa con Linux.\n";
  else
    inform->line = 0;
}

void  execute_second_c(t_inform *inform)
{
  if (!strcmp(inform->line, "a"))
    inform->answer = "\e[4;33mRed SAN:\e[0m Es una red de almacenamiento dedicado que proporciona acceso de nivel de bloque a varios LUN.\n";
  else if(!strcmp(inform->line, "b"))
    inform->answer =  "\e[4;33mFiber Channel:\e[0m Canal d fibra: Es una tecnologia de red de almacenamiento.\n";
  else if(!strcmp(inform->line, "c"))
    inform->answer =  "\e[4;33miSCSI:\e[0m (internet SCSI): Standar que permite el uso del protocolo SCSI sobre redes TCP/IP.\n";
  else
    inform->line = 0;
}

void  execute_second_d(t_inform *inform)
{
  if (!strcmp(inform->line, "a"))
    inform->answer = "\e[4;33mFlexpod:\e[0m Infraestructura convergente entre Cisco + NetApp.\n";
  else if(!strcmp(inform->line, "b"))
    inform->answer =  "\e[4;33mExpressPod:\e[0m (Netapp) Facilita la puesta en marcha de una infraestructura compartida.\n";
  else if(!strcmp(inform->line, "c"))
    inform->answer =  "\e[4;33mBlade server:\e[0m Es un tipo de computadora para los CPD, diseñado para aprovechar el espacio, reducir el consumo y simplificar su explotacion.\n";
  else if(!strcmp(inform->line, "d"))
    inform->answer =  "\e[4;33mFabric interconnect:\e[0m Es un switch o unidad principal. Es un chassis donde se conectan los componentes del servidor..\n";
  else
    inform->line = 0;
}

void  execute_second_e(t_inform *inform)
{
  if (!strcmp(inform->line, "a"))
    inform->answer = "\e[4;33mUCMS:\e[0m Unified Cisco Manager System.\n";
  else if(!strcmp(inform->line, "b"))
    inform->answer =  "\e[4;33mScrub polity:\e[0m Si esta habilidato, destruye todos los datos de cualquier local drive.\n";
  else
    inform->line = 0;
}

void  execute_second(t_inform *inform)
{
  if (inform->first == 'a')
    execute_second_a(inform);
  else if (inform->first == 'b')
    execute_second_b(inform);
  else if (inform->first == 'c')
    execute_second_c(inform);
  else if (inform->first == 'd')
    execute_second_d(inform);
  else if (inform->first == 'e')
    execute_second_e(inform);
}

void  execute_command(t_inform *inform)
{
  if (!strcmp(inform->line, "exit"))
  {
    inform->state = 0;
    return ;
  }
  if (inform->step == 0)
    execute_first(inform);
  else if (inform->step == 1)
  {
    if (!strcmp(inform->line, "back"))
    {
      inform->step--;
      return ;
    }
    execute_second(inform);
  }
}

int   check_command(t_inform *inform)
{
  return (!!inform->line);
}

void  print_answer(t_inform *inform)
{
  printf("%s\n", inform->answer);
  inform->answer = 0;
}

void  execute()
{
  t_inform *inform;

  inform = 0;
  if (!(inform = fill_inform(inform)))
    return ;
  put_tittle();
  while(inform->state)
  {
    put_posibilities(inform);
    put_pront(&inform->line);
    execute_command(inform);
    if (!check_command(inform))
      printf("\e[31mElija una opción correcta\e[0m\n\n");
    if (inform->answer)
      print_answer(inform);
    printf("-------------------------------------------------\n");
  }
}

int   main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  execute();
  return (0);
}
