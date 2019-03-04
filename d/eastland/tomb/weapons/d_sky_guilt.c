#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "Sky Guilt", "�� ���� ��");
        add( "id", ({ "sword", "sky guilt","guilt" }) );
        set_short( "�� ���� ��" );
        set_long(
  "�� ���� �� -----  һ�Ѵ�˵�е��Ϲ���������������൱���죬ͨ����ڡ�����\n"
  "�ײ�����һ��а����а�������в�ʱ��������Ĺ�â���������Ϸ��и�С������\n"
  "����������ʲ�ᶫ������֧����������\��\��С����Ƭ����ɣ�����������ʱ��һ\n"
  "�����ķ������\��\��С�۾�������������������˵����ħ���������֮һ����\n"
  "��һ����Ȼ�����鴫��\n"
        );
        set( "unit", "��" );
        set( "type", "longblade" );
        set( "weapon_class", 43 );
        set( "min_damage", 28 );
        set( "max_damage", 45 );
//        set( "bleeding", 25);
        set( "weight", 95 );
//        set( "hit_func", "my_special" );
        set( "special_damage", 10 );
        set( "special_c_msg",
             "����ͻȻ�ֽ��\��\����Ƭ�����������ϣ����ͨ����ɻ�!!\n\n" );
        set( "wield_func", "body_effect" );
        set( "extra_look",
             "һƬа��ĺ�������Χ����$N��������\n" );
        set( "value", ({ 300, "gold" }) );
        set( "no_sale", 1 );
}

int my_special(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    int my_int,vic_int;
    int my_str,vic_str;
    int now_sp, now_hp;
    string c_msg,msg;

    if( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) return 0;
    my_kar = (int)holder->query_stat("kar");
    vic_kar =(int)victim->query_stat("kar");
    my_int = (int)holder->query_stat("int");
    vic_int =(int)victim->query_stat("int");
    my_str = (int)holder->query_stat("str");
    vic_str =(int)victim->query_stat("str");
    if( random(my_kar *3 +my_int*3)+ my_str < vic_kar+3+vic_int+vic_str) 
       return 0;
    now_sp = (int)holder->query( "spell_points" );
    if( ( now_sp < 7 ) ) return 0;
        else {

                c_msg = (string)query("special_c_msg");
                victim->receive_special_damage( "magic" , dam );
                victim->set("last_attacker", holder );
                now_hp = (int)holder->query( "hit_points" );
                if ( holder->query_temp("NO_DRAIN") ) 
                	now_hp = now_hp + dam + 50;
                else    now_hp = now_hp - dam - 25;
                if ( now_hp > (int)holder->query("max_hp") )
                	now_hp = (int)holder->query("max_hp");
                holder->set("hit_points", now_hp);
                now_sp = now_sp - 7;
                holder->set("spell_points", now_sp);
                if( !c_msg ) return 0;
                tell_object( holder,
                        "\n���"+query("c_name")+set_color(c_msg,"HIR")+"\n" );
                tell_room( environment(holder), 
                holder->query("c_name") + "��"+query("c_name")+set_color(c_msg,"HIR")+"\n",
                        holder );
                return dam;
     }
}

void body_effect()
{
 object holder;

 holder = environment(this_object());
 tell_object( holder, 
     "\nһ���������а����з�����Ѹ���������㡣\n" );
}
