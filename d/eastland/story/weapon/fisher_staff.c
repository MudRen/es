#include <mudlib.h>

inherit WEAPON;

void create()
{
     set_name("fish blunt","����");
     add( "id",({"blunt"}) );
     set_short("����");
     set_long(@C_LONG
һ����ͨ�ĵ��ˣ���������ǧ�����Ĺκۡ�
C_LONG
      );
     set( "unit", "��");
     set("weight",90);
     set("value", ({ 250, "silver" }));
     setup_weapon( "blunt", 20, 8, 15 );
}
