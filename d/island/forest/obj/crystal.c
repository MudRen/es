#include "../tsunami.h"

inherit OBJECT;

void create()
{
     set_name("Red Crystal","��ɫ��Сˮ��");
     add("id",({"crystal"}) );
     set_short("��ɫ��Сˮ��");
     set_long(@LONG
�����˻ʹ�û����ɵ�ˮ���������ϵط����������Ľ��������ϲ��ϵķ�����ɫ
�����⣬ʹ����ð������֣�
LONG
              );
     set("unit","��");
     set("weight",10);
     set("no_sale",1);
     set("give_to_sasami",1);
 }