// Echo/item/broom.c

#include "../echobomber.h"
inherit OBJECT;

void create()
{
     set_name("broom","ɨ��");
     set_short("a broom","ɨ��");
     set_long(
      "just a broom.\n",
      "һ����ͨ��ɨ��.�����������ȥɨɨ�ҳ�.\n"
      );
     set( "unit", "��");
     set("weight",35);
     set("value", ({ 10, "silver" }));
}
