#include "../takeda.h"
inherit OBJECT;

void create()
{
     set_name("fish rod","����");
     set_short("fish rod","����");
     set_long(
      "һ�����������ɵļ򵥵��ͣ������������ߣ�����͵�����\n"
      );
     set( "unit", "��");
     set("weight",40);
     set("value", ({ 20, "silver" }));
}
