#include "../tsunami.h"

inherit ARMOR;

void create()
{
  set_name("Scale shield","�۶�");
  add("id",({"scale","shield"}) );
  set_short("�۶�");
  set_long(@LONG
����Ǵ��������û����ɵ�ǿ�����ơ�
LONG
          );
  set("unit","��");
  set("type","shield");
  set("material","stone");
  set("armor_class",6);
  set("defense_bonus",1);
  set("weight",200);
  set("special_defense",(["fire":1,"sleet":1]) );
  set("value",({600,"silver"}) );
}
