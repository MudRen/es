#include "../tsunami.h"

inherit ARMOR;

void create()
{
  set_name("Bone Helmet","���ǿ�");
  add("id",({"bone","helmet"}) );
  set_short("���ǿ�");
  set_long(@LONG
����Ǵ�˵����ħ��ͷ�������ɵ�ͷ����ֻ�������ϵ���˸����ɫ�Ĺ�â��
LONG
          );
  set("unit","��");
  set("type","head");
  set("material","stone");
  set("armor_class",5);
  set("defense_bonus",3);
  set("weight",200);
  set("value",({100,"gold"}) );
  set("no_sale",1);
}
