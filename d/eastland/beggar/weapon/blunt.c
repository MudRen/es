#include "../dony.h"

inherit WEAPON;

void create()
{
     set_name("dog blunt","���");
     add( "id",({"blunt"}) );
     set_short("���");
     set_long(@C_LONG
һ������ͨͨ�İ���, ��������á�
C_LONG
      );
     set( "unit", "��");
     set("weight",30);
     set("value", ({ 25, "silver" }));
     setup_weapon( "blunt", 20, 12, 20 );
}
