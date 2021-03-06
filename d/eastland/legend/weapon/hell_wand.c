#include <mudlib.h>
#include "/d/eastland/legend/magic.c"

inherit WEAPON;

void create()
{
    set_name("hell's wand","业火之杖");
    add("id",({"wand","hell's wand"}) );
    set_short("业火之杖");
    set_long(@C_LONG
这是一把由火山喷出来的碎屑经过急速凝固所形成的一把魔杖。这把魔杖威力极大
，倘若失控所造成的伤害是无可计量的。
C_LONG           
           );
    set("unit","把");
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
           sprintf("\n唉呀,你手中的%s被敌人敲坏了!!!\n\n",my_name));
       tell_room(environment(holder),
           sprintf("%s手中的%s被敌人敲坏了～～\n",ho_name,my_name),holder);
       add("short"," (受损)") ;
       add("c_name"," (受损)");
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
       "\n你手中的%s开始聚集一团火焰， 逐渐形成一只炙热的火鸟 － 凯撒之鹰。\n\n",my_name),
         "HIR")); 
    tell_room( environment(holder),set_color(sprintf(
       "\n%s手中的%s开始聚集一团火焰， 逐渐形成一只炙热的火鸟 － 凯撒之鹰。\n\n",ho_name,my_name),
        "HIR"),holder);
    if ( !holder->query("npc") ) {
       delay=6;
       dam=35+random(3);
       add("charge_left",-1);
       holder->add("spell_points",-5);
       holder->block_attack(6);
       holder->set_temp("msg_stop_attack","(  你正在施法无法攻击!!  ) \n");
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
       tell_object(holder,"\n没有目标物!!\n\n");
       return ;
    }
    venv=environment(victim);
    henv=environment(holder);
    if ( (venv != henv)||!victim ) {
       tell_object(holder,set_color("你将手上火球一丢, 炸出一个大洞。\n\n",
           "HIR"));	
       tell_room(henv,set_color(sprintf(
         "%s将手上火球一丢, 炸出一个大洞。\n\n",ho_name),
           "HIR"),holder);
       return;
    } 
    victim->receive_special_damage("fire",dam);    
    tell_object(holder,set_color(
       "\n你手指向前一指, 炎鸟「凯萨之鹰」冲向此地中心, 「轰隆」的一声!\n\n\n",
           "HIR"));
    tell_room(venv,set_color(sprintf(
       "\n%s手指向前一指, 炎鸟「凯萨之鹰」冲向此地中心, 「轰隆」的一声!\n\n\n",ho_name),
           "HIR"),holder);
    tell_room(venv,sprintf(
        "( 你已经%s了。)\n",set_color("奄奄一息","HIR") ),holder);
    victim->kill_ob(holder);
    victim->set("last_attacker", holder );
    return ;
}
