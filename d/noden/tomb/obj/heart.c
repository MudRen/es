#include <mudlib.h>

inherit ARMOR;

void create()
{
   set_name( "golden heart", "�ƽ�֮��" );
   add( "id", ({ "heart" }) );
   set_short( "�ƽ�֮��" );
	set_long(
   "����һ�Ŵ��������, ����ɢ��һ������Ĺ���, ����������ص�������\n"
	);
	set( "type", "misc" );
   set( "material", "healer" );
   set( "weight", 50 );
   set( "prevent_drop", 1 );
   set( "defense_bonus", 6 );
   set( "extra_skills", ([ "anatomlogy" : 10 ]) );
   set( "equip_func", "equip_heart" );
   set( "unequip_func", "unequip_heart" );
}

int equip_heart()
{
   int op_succ, op_fail, op_times;

   op_succ = this_player()->query("op_succ_count");
   op_fail = this_player()->query("op_fail_count");
   op_times = op_succ + op_fail;

   if( op_times > 100 ) {
        set( "defense_bonus", 10 );
        tell_object( this_player(),
          "�ƽ�֮����ҫ������ѣĿ�Ĺ��!\n" );
        return 1;
   }
   if( op_times < 100 && op_times > 50 ) {
        set( "defense_bonus", 8 );
        tell_object( this_player(),
          "�ƽ�֮����ҫ��ʮ�ֲ��õĹ�â!\n" );
        return 1;
   }
}

int unequip_heart()
{
   set( "defense_bonus", 6 );
   return 1;
}
      
