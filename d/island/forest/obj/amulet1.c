#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Royal amulet","���߻����");
      add("id",({"amulet"}) );
      set_short("���߻����");
      set_long(@LONG
�������������д������Ȩ������������ഫ�����ػ���͸����ҵճ������
LONG
              );
      set("unit","ö");
      set("type","misc");
      set("material","element");
      set("armor_class",0);
      set("defense_bonus",8);
      set("special_defense",(["fire":30,"cold":20,"evil":-40]) );
      set("weight",10);
      set("no_sale",1);
      set("value",({100,"gold"}) );
}              
                    
