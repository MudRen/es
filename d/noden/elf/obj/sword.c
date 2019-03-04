
#include <mudlib.h>
inherit WEAPON;

void create()
{
   set_name( "ether-genius sword", "��̫���齣" );
        add( "id",({ "sword", "longsword" }) );
   set_short( "��̫���齣" );
        set_long(
            "���Ǿ�������ʹ�õĳ��������ı�����մ���˵��˵���Ѫ�������ְ���ɫ\n"
         "�İ���, �����Ľ������ɷ���, �ɼ�����һ�Ѻ���������ֻ��ս���������\n"
         "���ܳ�ݷ�����Ǳ�ڵ�������\n"
        );
        set( "unit", "��");
        set( "weapon_class", 42 );
        set( "type", "longblade" );
   set( "min_damage", 22 );
   set( "max_damage", 50 );
        set( "nosecond",1);
        set( "weight", 210 );
        set( "value", ({ 1000, "gold" }) );
   set( "hit_func", "weapon_hit" );
}

int weapon_hit(object victim, int damage)
{
   object owner;
   int myscore;

   owner = environment();
   myscore = owner->query( "war_score" );

   if( myscore < 50000 ) return 0;
   if( myscore > 500000 ) myscore = 500000;
// �������ϲ����������⹥����
// ����˺� 50��
   if( random(20) > 2 ) return 0;
   tell_object( owner,
"\n�����е���̫���齣��ۼ���һ������Ĺ�â����"+victim->query("c_name")+"\n" );
   tell_object( victim,
"\n"+owner->query("c_name")+"���е���̫���齣��ͻȻ����һ������Ĺ�â������!\n" );
   tell_room( environment(owner),
   owner->query("c_name")+"���е���̫���齣��ͻȻ��һ�ɹ�â����"+victim->query("c_name")+"!\n", ({ owner, victim }) );
   victim->receive_special_damage( "energy", myscore/10000 );
   return myscore/10000;
}
