#include <mudlib.h>

inherit WEAPON;

void create()
{
     set_name("Origin wand", "�������");
     add ("id",({ "wand",}) );
     set_short("�������");
     set_long(@LONG
һ�ѻ�ɫ��ħ�ȡ���˵�������������������ص�ԭʼʱ�ĵ�ΰ��ħ��������Ϊǰ
�˱�����һ�ǵĲ�������ʧȥ����ʮ��֮�ŵ�������˵����ˣ���ʣ�ŵ���������
�������ӡ�
LONG
     );
     set( "unit", "��" );
     set("damaged",0);
     set( "weapon_class", 35 );
     set( "type", "wand" );
     set( "min_damage", 20 );
     set( "max_damage", 30 );
     set("special_things",1);
     set( "value", ({ 4000, "silver" }) );
     set( "charge_left",10);
     set("weight",100);
     set("hit_func","wand_damage");
}
int wand_damage(object victim,int damage)
{
    object holder;
    string my_name,ho_name,vic_name;
    int hint,skill,dam;
    
    if( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) 
        return 0;
    if ( query("damaged") ) return 0;
    if ( (holder->query("spell_points") < 20 )&&(!holder->query("npc")) )
       return 0;
    my_name=query("c_name");
    ho_name=holder->query("c_name");
    vic_name=victim->query("c_name");
    if( (query("charge_left")<1 ) && ( !query("damaged") ) ) {
       set("damaged",1);
       tell_object(holder,
           sprintf("\n���أ����˺ݺ��������е�%sһ�������%s�������û���!!!\n\n",my_name,my_name));
       tell_room(environment(holder),
           sprintf("%s���е�%s�������û��ˡ�\n",ho_name,my_name),holder);
       add("short"," (����)") ;
       add("c_name"," (����)");
       setup_weapon("wand",30,12,20);
       return 0;
    }
    hint=holder->query_stat("int");
    skill=holder->query_skill("wand");
    if ( random(skill + hint*3) > (int)query("weapon_class") )
       return 0;
                         
    dam=45+random(10);
    tell_object( holder,set_color(sprintf(
       "\n�����е�%s��������¡¡��������Ю����Ѹ������%s��ͷ�ϣ�\n\n"
       ,my_name,vic_name),"HIB")); 
    tell_room( environment(holder),set_color(sprintf(
       "\n%s���е�%s��������¡¡��������Ю����Ѹ������%s��ͷ�ϣ�\n\n"
       ,ho_name,my_name,vic_name),"HIB"),({holder,victim}));
    tell_object( victim,set_color(sprintf(
       
         "\n%s���е�%s��������¡¡��������Ю����Ѹ���������ͷ�ϣ�\n\n"
       ,ho_name,my_name),"HIB"));
    if ( !holder->query("npc") ) {
       add("c
       harge_left",-1);
       holder->add("spell_points",-20);
       dam=35+random(10);
    }
    victim->receive_special_damage("eletric",dam);
    victim->set("last_attacker", holder );
    return dam;
}
