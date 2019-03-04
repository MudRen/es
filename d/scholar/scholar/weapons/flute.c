#include <mudlib.h>

inherit WEAPON;

void create()
{
   set_name( "old_jade flute", "������" );
   add("id", ({"flute"}) );
   set_short( "������" );
   set_long(
     "����һֻ�ɺ�����������ɵ�����������沼�����λ��ƣ����⻹����\n"
     "׭�Ŀ�������С�֣��������������˵���ǵ���ʵ������͵Ķ�����\n" );
   set( "unit", "ֻ" );
   set( "type", "longblade" );
   set( "hit_func", "weapon_hit" );
   set( "weight", 50 );
   set( "weapon_class", 35 );
   set( "no_sale", 1 );
   set( "min_damage", 20 );
   set( "max_damage", 36 );
   set( "value", ({ 2000, "silver" }) );
   set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
   object owner;
   int inte, intv, fp;

   owner = environment();
   inte = owner->query_stat("int");
   fp = owner->query("force_points");
   if (!((string)owner->query("class")=="scholar")){
     tell_object( owner,
     "\n�����е����﷢��һ������������ ! �㲻�����ҵ����ˡ�\n\n");
     owner->receive_special_damage("energy",inte/2);
     return 0;
   }
   if (!victim) return 0;
   intv = victim->query_stat("int");
   if( random(inte*3)>(intv*2) && fp >2 ) {
       tell_object( owner,
       "\n�㽫һ���������������, ����ͻȻ����һ��������"+victim->query("c_name")+"��ȥ\n\n" );
       tell_object( victim,
     "\n" +
          owner->query("c_name") + "������ͻȻ����һ����������Ϯ��!\n\n" );
       tell_room( environment(owner),
     "\n" +
         owner->query("c_name") + "������ͻȻ��" + victim->query("c_name") + "���һ������!\n\n"
         , ({ victim, owner }) );
       victim->receive_special_damage( "energy", inte/2 );
          owner->add( "force_points", -3 );
          return inte/2;
	}
}
