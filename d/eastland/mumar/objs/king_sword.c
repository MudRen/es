#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("empire sword", "�з�����");
        add ("id",({ "sword" }) );
        set_short("�з�����");
        set_long(
          "����һ֧�����鱦���ûƽ����ʵı�������˵�ǻʵ����͸��س������\n"
          "��ӵ����ѱ������˿��Դ��л�������ն���ࡣ����Ҳ�д���˵��ѽ���\n"
          "��������ǼپͲ��ö�֪��...\n"
        );
        set( "unit", "��");
        set( "weapon_class", 35 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 36 );
        set( "weight", 200 );
        set( "value", ({ 5200, "silver" }) );
        set( "hit_func", "weapon_hit" );
        set( "no_sale",1 );
}
 
int weapon_hit( object victim, int damage )
{
    object owner,target;
    int dexx, t_dexx, sp, dam, ali;
 
    owner = environment();
    target = owner->query_attacker();
    dexx = owner->query_stat("dex");
    t_dexx= target->query_stat("dex");
    sp = owner->query("spell_points");
    ali = owner->query("alignment");
    if (ali < 0) dam = 1;
    if (ali > 50000) dam = (dexx - t_dexx) * 5 ;
    else dam = (dexx - t_dexx) * ali/10000;
    if (dam>28) dam =28;
    if( random(10)>6 && sp > 6 && (dexx-t_dexx)>3 ) {
       tell_object( owner,set_color(
         "\n�����е��з��������ҵ��𶯣�ͬʱһ���ྻ��覵�����ɫǿ�⣬������˵�Ҫ����\n\n","HIW") );
       tell_room( environment(owner),
         set_color(owner->query("c_name") + "���ݵ�����һת�����б���ɢ���һ���ྻ��覵�����ɫ��ǿ�⣬ֱ�����˵�Ҫ����\n\n","HIW")
         ,owner);
       victim->receive_special_damage( "divine", dam );
       owner->add( "spell_points", -6);
       return dam;
     }
}
