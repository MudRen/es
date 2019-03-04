#include <mudlib.h>
#include "/d/eastland/legend/magic.c"

inherit WEAPON;

void create()
{
    set_name("hell's wand","ҵ��֮��");
    add("id",({"wand","hell's wand"}) );
    set_short("ҵ��֮��");
    set_long(@C_LONG
����һ���ɻ�ɽ���������м���������������γɵ�һ��ħ�ȡ����ħ����������
������ʧ������ɵ��˺����޿ɼ����ġ�
C_LONG           
           );
    set("unit","��");
    setup_weapon("wand",30,10,20);
    set("charge_left",10);
    set("damaged",0);
    set("weight",100);
    set("value",({150,"gold"}));
    set( "wield_func","wield_wand");
    set( "unwield_func","unwield_wand");
    set("hit_func","wand_damage");
    set("no_sale",1);
}
int wield_wand()
{
    set("prevent_drop",1);
    return 1;
}
int unwield_wand()
{
    delete("prevent_drop");
    return 1; 
}                  
int wand_damage(object victim,int damage)
{
    object holder;
    string my_name,ho_name;
    int delay,bonus,dam,holder_int,victim_int;
    
    if( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) 
        return 0;
    if ( query("damaged") ) return 0;
    if ( holder->query("spell_points") < 5 )
       return 0;
    my_name=query("c_name");
    ho_name=holder->query("c_name");
    if( (query("charge_left")<1 ) && ( !query("damaged") ) ) {
       set("damaged",1);
       tell_object(holder,
           sprintf("\n��ѽ,�����е�%s�������û���!!!\n\n",my_name));
       tell_room(environment(holder),
           sprintf("%s���е�%s�������û��ˡ���\n",ho_name,my_name),holder);
       add("short"," (����)") ;
       add("c_name"," (����)");
       setup_weapon("wand",20,8,15);
       return 0;
    }
    if( query("wand_cast") ) return 0;
    holder_int=holder->query_perm_stat("int");
    victim_int=victim->query_perm_stat("int");
    bonus = holder_int - victim_int-15+random(6);
    if ( holder->query("npc") ) bonus += random(20);
    if ( bonus < 2 ) return 0;     
        
    dam=60+random(35);
    delay=4; 
    set("wand_cast",1);
    tell_object( holder,set_color(sprintf(
       "\n�����е�%s��ʼ�ۼ�һ�Ż��棬 ���γ�һֻ���ȵĻ��� �� ����֮ӥ��\n\n",my_name),
         "HIR")); 
    tell_room( environment(holder),set_color(sprintf(
       "\n%s���е�%s��ʼ�ۼ�һ�Ż��棬 ���γ�һֻ���ȵĻ��� �� ����֮ӥ��\n\n",ho_name,my_name),
        "HIR"),holder);
    if ( !holder->query("npc") ) {
       delay=6;
       dam=35+random(3);
       add("charge_left",-1);
       holder->add("spell_points",-5);
       holder->block_attack(6);
       holder->set_temp("msg_stop_attack","(  ������ʩ���޷�����!!  ) \n");
    }
    call_out("recover",delay,holder,victim,dam);                      
    victim->set("last_attacker", holder );
    return 1;
}
void recover(object holder,object victim,int dam)
{
    object venv,henv;
    string ho_name;
    
    delete("wand_cast");
    ho_name=holder->query("c_name");
    if ( !victim ) {
       tell_object(holder,"\nû��Ŀ����!!\n\n");
       return ;
    }
    venv=environment(victim);
    henv=environment(holder);
    if ( (venv != henv)||!victim ) {
       tell_object(holder,set_color("�㽫���ϻ���һ��, ը��һ���󶴡�\n\n",
           "HIR"));	
       tell_room(henv,set_color(sprintf(
         "%s�����ϻ���һ��, ը��һ���󶴡�\n\n",ho_name),
           "HIR"),holder);
       return;
    } 
    victim->receive_special_damage("fire",dam);    
    tell_object(holder,set_color(
       "\n����ָ��ǰһָ, ���񡸿���֮ӥ������˵�����, ����¡����һ��!\n\n\n",
           "HIR"));
    tell_room(venv,set_color(sprintf(
       "\n%s��ָ��ǰһָ, ���񡸿���֮ӥ������˵�����, ����¡����һ��!\n\n\n",ho_name),
           "HIR"),holder);
    tell_room(venv,sprintf(
        "( ���Ѿ�%s�ˡ�)\n",set_color("����һϢ","HIR") ),holder);
    victim->kill_ob(holder);
    victim->set("last_attacker", holder );
    return ;
}
