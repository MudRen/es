#include "../tsunami.h"

inherit ARMOR;

void create()
{
  set_name("Turtle Boots","���սѥ");
  add("id",({"turtle","boots"}) );
  set_short("���սѥ");
  set_long(@LONG
����Ǵ�˵�������Ĺ�������ɵ�սѥ��
LONG
          );
  set("unit","˫");
  set("type","feet");
  set("material","stone");
  set("armor_class",8);
  set("defense_bonus",2);
  set("weight",100);
  set("value",({200,"gold"}) );
}
