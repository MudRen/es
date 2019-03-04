#include <mudlib.h>
inherit WEAPON;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
  set_name("orc blunt", "����Ȩ��");
  add("id", ({"blunt","orc blunt"}) );
  set_short("a orc blunt","����Ȩ��");
  set_long(
   "һ�Ѻڸ����ɵ�Ȩ�ȣ��������һֻ�����˵ĵ���\n"
  );
  set( "unit", "��" );
  set( "weapon_class", 40 );
  set( "type","blunt");
  set( "min_damage", 15 );
  set( "max_damage", 40 );
  set( "weight", 100 );
  set( "value", ({ 8000, "silver" }) );
  set( "hit_func", "weapon_hit" );
  set_c_verbs ( ({
   "%s���䡸һ�����ϡ����������͡���ʽ������%s",
   "%s���䡸����ն������ա����ʽ������%s",
   "%s���䡸ʮ�ֶ�����ǧ��������ʽ��ն��%s",
   "%s���䡸����Ѫ�ˡ���ħ��Լ����ʽ������%s",
             }) ) ;
}

int weapon_hit( object victim, int damage )
{
   object owner ;
   int inte ;

   owner = environment();
   inte = owner->query_stat("str");
   if (!victim) return 0;
   if ( random(100) > 80 ) {
     tell_object( owner,
       "\nȨ��ͻȻ��â���ɣ��������죬һ��������"
           +victim->query("c_name")+"��ȥ\n\n" );
     tell_object( victim,
       "\n"+owner->query("c_name") 
           + "Ȩ��ͻȻ�������첢����һ�����⣬����Ϯ��!\n\n" );
     tell_room( environment(owner),
       "\n" +owner->query("c_name") 
           + "��Ȩ��ͻȻ�������첢����һ��������" + victim->query("c_name") 
           + "��ȥ!\n\n", ({ victim, owner }) );
     victim->receive_special_damage( "energy", inte );
     return inte;
   }
}
