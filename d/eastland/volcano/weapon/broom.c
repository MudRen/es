#include "../oldcat.h"

inherit WEAPON;

void create()
{
     set_name("broom","ɨ��");
     set_short("ɨ��");
     set_long(
      "һ����ͨ��ɨ��.�����������ȥɨɨ�ҳ�.\n"
      );
     set( "unit", "��");
     set( "type","blunt");
     set("weight",35);
     set("value", ({ 20, "silver" }));
     set("weapon_class",10);
     set("min_damage",5);
     set("max_damage",15);
}
