#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky-bracers","��������");
        add( "id", ({"bracers" }) );
   set_short("��������");
        set_long(
"����һ���ܴ��������˵�Ư���������ǣ�����ֻ�и�һЩ�����������ˣ���\n"
                );
        set( "unit", "��");
        set ( "type", "hands" );
   set("armor_class",5);
      set("defense_bonus",3);
   set( "material", "thief" );
        set( "weight", 22 );
        set( "value", ({ 200, "gold" }) );
        set( "no_sale",1);
        set("extra_skills",(["backstab":10,"dodge":5]));
}
