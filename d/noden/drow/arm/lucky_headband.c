#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky headband", "����ͷ��");
   add( "id", ({ "headband" }) );
        set_short( "����ͷ��" );
        set_long(
@C_LONG
���������ɫ��ͷ����������β��֯��С���ı�ǣ���������
����Ȼ������Ҳ�Ǳ��ϵ���ʧ�Ķ����ɣ�
C_LONG
        );
        set( "unit", "��");
        set( "type", "head" );
        set( "material", "cloth" );
        set( "armor_class", 2 );
   set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "poison": 5, "fire": 10, "cold" : -15 ]) );
        set( "weight", 30 );
        set( "value", ({ 1960, "silver" }) );
   set( "no_sale", 1 );
        set( "equip_func","equip_headband" );
        set( "unequip_func","unequip_headband" );
}

void equip_headband()
{
        string cla,him;
        him=this_player()->query( "c_name" );
        cla=this_player()->query( "class" );
        if( cla!="thief" )
        {
         tell_object(this_player(),"\nֻ��С͵����������������ħ������\n\n");
         tell_room(environment(this_player()),
         "\n�㿴��"+him+"��������ͷ���ᣬ����ͯ�����������������һ�ؿ�ˮ���찡��\n\n",this_player());
        }
        else
        {
         tell_room(environment(this_player()),"\n�㿴��"+him+"��������ͷ���ᣬ�������������ƣ��񾭣�\n\n"
         ,this_player());
         tell_object(this_player(),"\n�����ͷ���ᣬ�о�����һ���ƺ�����Ů���������ߣ�\n\n"
         );    
   set( "armor_class", 6 );
   set("material","thief");
   set( "defense_bonus", 5 );
        }
        return ;
}

void unequip_headband()
{
        set( "armor_class",2 );
   set( "defense_bonus", 2 );
        return ;
}
                                                                                                
