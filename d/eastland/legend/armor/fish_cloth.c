#include <mudlib.h>

inherit ARMOR;

void create()
{
      set_name("fish cloth","����");
      add("id",({"cloth"}) );
      set_short("����");
      set_long(@C_LONG
һ��Ѱ�������˼��������·�����Ȼ��ƵĲ��Ǻ��³������ǣ���춳�����������
������ȴҲ�ṩ�����õķ�����
C_LONG           );
      set( "unit", "��" );
      set( "weight",50 );
      set( "type", "body" );
      set("material","cloth");
      set( "armor_class", 20);
      set( "defense_bonus", 5 );
      set("special_defense",
          (["poison":20,"acid":20,]) );
      set( "value", ({700, "silver" }) );
}                                                                                                             