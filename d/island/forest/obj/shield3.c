#include "../tsunami.h"

inherit ARMOR;

void create()
{
  set_name("Ratten shield","���ƶ�");
  add("id",({"ratten","shield"}) );
  set_short("���ƶ�");
  set_long(@LONG
���������������ɵĶ��ơ�
LONG
          );
  set("unit","��");
  set("type","shield");
  set("material","cloth");
  set("armor_class",4);
  set("defense_bonus",1);
  set("weight",100);
  set("value",({150,"silver"}) );
}
