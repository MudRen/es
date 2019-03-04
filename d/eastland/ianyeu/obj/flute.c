#include <mudlib.h>

inherit WEAPON;

void create()
{
   set_name( "flute", "����" );
   set_short( "����" );
   set_long(
     "����һֻ�ɴ�������ɵ�����������沼�����λ��ƣ�\n"
     "������׭�Ŀ�������С�֣���Ц����������\n" );
   set( "unit", "ֻ" );
   set( "type", "shortblade" );
   set( "hit_func", "weapon_hit" );
   set( "weight", 80 );
   set( "weapon_class", 41 );
   set( "nosecond", 1 );
   set( "min_damage", 20 );
   set( "max_damage", 35 );
   set( "value", ({ 1000, "silver" }) );
   set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
   object owner;
   int dex, fp;

   owner = environment();
   dex = owner->query_stat("dex");
   fp = owner->query("force_points");

   if( dex < 25 ) {
     tell_object( owner,
     "\n����㲻������, ���ﱻ��˦�˳�ȥ!\n\n" );
     this_object()->remove();
     return 0;
   }
   if( random(dex)<21 ) return 0;
   if( random(dex)>20 && fp<20 ) {
     tell_object( owner,
     "\n��������������, �����������������������������Լ�!\n\n" );
     owner->receive_special_damage( "energy", dex+random(15) );
     return 0;
     }
   else {
       tell_object( owner,
       "\n�㽫һ���������������, ����ͻȻ����һ��������"+victim->query("c_name")+"��ȥ\n\n" );
       tell_object( victim,
     "\n" +
          owner->query("c_name") + "������ͻȻ����һ����������Ϯ��!\n\n" );
       tell_room( environment(owner),
     "\n" +
         owner->query("c_name") + "������ͻȻ��" + victim->query("c_name") + "���һ������!\n\n"
         , ({ victim, owner }) );
        victim->receive_special_damage( "energy", dex+10 );
        owner->add( "force_points", -20 );
       return dex+10;
	}
}
