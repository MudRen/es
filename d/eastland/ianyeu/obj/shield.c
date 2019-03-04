#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "topaz shield", "������" );
        add( "id", ({ "shield" }) );
        set_short( "������" );
        set_long(
        "�㿴��һ��˶���ʴ��ľƻƱ�ʯ, ����ע����ʱ,\n"
        "�ݷ𿴵���Ϧ���������ľ�ɫ�����Ƿ���Ҫ��(rub)\n"
        "ȥ����Ļҳ�, �Ա㿴�����Щ?\n"
        );
        set("unit","��");
        set( "type", "shield" );
        set( "material", "element" );
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense", ([
               "fire" : -15, "cold": -15, "acid" : -15,
               "energy" : 12, "magic" : 12, "electric" : 12
          ]) );
        set( "weight", 100 );
        set( "value", ({ 2150, "silver" }) );
        set( "no_sale", 1 );
}

void init()
{
   add_action( "rub_shield", "rub" );
}

int rub_shield(string str)
{
   if( !str || !id(str) )
        return notify_fail( "��ҪĦ��ʲ��?\n" );
   if( (int)this_player()->query("spell_points")<50 )
        return notify_fail( "��ľ���̫����, �޷���ЧĦ�����ơ�\n" );
   if( query("light") )
        return notify_fail( "���Ѿ���Ħ�����ˡ�\n" );
   write( "��������Ħ������, �����𽥵ط���΢���Ĺ�â��\n" );
   this_player()->add( "spell_points", -50 );
   set( "light", 1 );
   call_out( "run_out", 240 );
   return 1;
}

void run_out()
{
   object owner;

owner = environment(this_object());

   if( living(owner) )
   tell_object( owner, "�����ܵĵ�⽥��΢��...�������ֹͣ����...\n" );
   set( "light", 0 );
}
