#include "../dony.h"

inherit WEAPON;

void create()
{
     set_name("broom","��ɨ��");
     add( "id",({"broom"}) );
     set_short("��ɨ��");
     set_long(@C_LONG
һ������ͨͨ����ɨ�㡣��������ɨ��֮��,�㿴������ʲ�Ṧ�á�
C_LONG
      );
     set( "unit", "��");
     set("weight",30);
     set("value", ({ 25, "silver" }));
     setup_weapon( "blunt", 30, 15, 30 );
}
