#include "../zeus.h"
inherit ARMOR;

void create()
{
        set_name("wooden armband","��ľ�ۻ�");
        add( "id", ({ "wooden","armband" }) );
        set_short("wooden armband", "��ľ�ۻ�");
        set_long(@CLONG
����һ˫��ǧ����������ĥ�Ƴɵıۻ�����֪����ʲ��Ե��ʹ����
��ɫ�����ī��ɫ������ͺ�ɫ�Ŀ��״���Ļ����պû�Ȼһ���
���Ĳ�����
CLONG
);
        set( "unit", "˫");
        set( "type", "arms" );
        set( "material", "wood");
        set( "armor_class", 3 );
        set( "defense_bonus", 4 );
        set( "equip_func","bonus_up");
        set( "unequip_func","stop_bonus_up");
        set( "special_defense",
               ([ "all":4 ]));
        set( "weight", 70 );
        set( "value", ({ 1800, "silver" }) );
}
void bonus_up()
{     object ob;
      if((ob=present("black platemail",environment(this_object()) ))&&
         (ob->query("equipped"))){
         set( "defense_bonus",5);
         set( "armor_class",4);
         tell_object(environment(this_object()),
 "���㴩�Ϻ�ľ�ۻ�ʱ�������ͺ�ɫ���׽��ܽ�ϣ��γ�һ�׷ǳ������װ����\n"
         );
         return 0;
         }
         }
void stop_bonus_up()
 {
 set("defense_bonus",4);
 set("armor_class",3);
 }
