#include <mudlib.h>

inherit ARMOR;

void create()
{
      set_name("daoist's cloth","éɽ������");
      add("id",({"cloth"}) );
      set_short("éɽ������");
      set_long(@C_LONG
һ��éɽ��ʿ�������·�����������һ�����Ե�ͼ�Ρ�
C_LONG           );
      set( "unit", "��" );
      set( "weight",100 );
      set( "type", "body" );
      set("material","mage");
      set( "armor_class", 34);
      set( "defense_bonus", 7 );
      set("special_defense",
          (["fire":30,"evil":30,"magic":30,"cold":-30,"mental":-70]) );
      set( "value", ({1500, "silver" }) );
}                                                                                                             