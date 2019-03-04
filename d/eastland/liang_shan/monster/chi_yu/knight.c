#include <mudlib.h>

inherit "/d/eastland/liang_shan/monster/chi_yu_group";

void create()
{

	::create();
	set_level(17);
	set_name( "snaky warrior", "ÉßÈËÕ½Ê¿" );
	add( "id", ({ "warrior" }) );
	set_short( "ÉßÈËÕ½Ê¿" );
	set_long(@C_LONG
ÉßÈËÆäÊµ¿ÉÒÔËµÊÇÃ»ÓĞ½ÅµÄòáòæÈË£¬ËäÃ»ÓĞòáòæÈËÄÇ÷áÇ¿×³
µ«ÊÇÈ´ÓĞÔ¶¸ßì¶ËûÃÇµÄÖÇ»Û¡£¾¡¹ÜÈç´Ë£¬¾­¹ıÑÏ¸ñÑµÁ·µÄÉß
ÈË»¹ÊÇ¿ÉÒÔ³ÉÎªÓÂÃÍµÄÕ½Ê¿£¬²¢ÇÒÄÜ¹»×ÔÓÉÊ¹ÓÃĞí¶à²»Í¬µÄ
Õ½Êõ¡£
C_LONG	);
	set( "unit", "Ãû" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -500 );
	set_natural_weapon(20,15,15);
	set_natural_armor(20,20);
	set( "special_defense", ([ "all": 20,"none":10 ]) );
        
        set("aim_difficulty",
        ([ "critical":25, "vascular":20, "weakest":35, "ganglion":5 ]));

	set("chi_yu_group",1);
	set( "wealth/silver", 250 );
	set_perm_stat( "str", 24 );
	set_perm_stat( "dex", 24 );
	set( "aiming_loc", "weakest" );
	set_skill( "anatomlogy",60 );
	set_skill( "longblade", 90 );
	set_skill( "parry", 80 );
	set_skill( "block",85 );
	set("tactic","berserk");
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"[1mÉßÈËÕ½Ê¿´ó½Ğ: ò¿ÓÈ´óÍõ¾Í¿ì¹ıÀ´ÁË£¬´ó¼Ò¿ì°ÑÀ¬»øÇåÇ¬¾»£¡[0m\n",
		"[1mÉßÈËÕ½Ê¿ËµµÀ: ¶ªÏÂÎäÆ÷£¬²»Òª×öÎŞÎ½µÄµÖ¿¹£¡[0m\n",
		"[1mÉßÈËÕ½Ê¿ºÈµÀ: »ÆÖÓ»ÙÆú£¬Íß¸ªÀ×Ãù£¬ÄãÃÇµÄÓ¢ĞÛ¶¼µ½ÄÇÈ¥ÁË£¡[0m\n"
	}) );

        wield_weapon( "/d/deathland/weapon/sword03" );
//        equip_armor( "/d/noden/drow/arm/a18" );
  //      equip_armor( "/d/noden/drow/arm/a10" );
    //    equip_armor( "/d/noden/drow/arm/a14" );
}

int my_tactic()
{
	object victim;
        
        if ( !victim = query_attacker()) return 0;
	
	if( random(20)<3 ) {
        tell_object(victim,set_color( "ËµÊ±³Ù£¬ÄÇÊ±¿ì£¬ÉßÈËÕ½Ê¿ÓÃËû³¤³¤µÄÎ²°ÍÏòÄãÏÂÅÌÉ¨È¥£¬ÄãÒ»¸ö\n"
        "²»Ğ¡ĞÄ£¬±»Ëû´ò·­ÔÚµØÉÏ¡£\n","HIM",victim));
        tell_room(environment(this_object()),set_color("ËµÊ±³Ù£¬ÄÇÊ±¿ì£¬ÉßÈËÕ½Ê¿ÓÃËû³¤³¤µÄÎ²°ÍÏò"
        +victim->query("c_name")+"µÄÏÂÅÌÉ¨È¥£¬½«Ëû´òµ¹ÔÚµØ¡£\n","HIM",victim),victim);
        victim->block_attack(3);
        victim->set_temp("msg_stop_attack", "\n£¨ ÄãÏÖÔÚË¤µ¹ÔÚµØÎŞ·¨¶¯µ¯ £©\n\n");
        victim->receive_damage(5);
        return 1;
	} else return 0;
}

void relay_message(string class, string str)
{
        int i,hitp,hp1,hp2;
        string name,direction,tmp,guild;
        object victim,mob,env,*who,bandage;
        mixed bandaged,bleed;
        ::relay_message(class,str);
        
        
        if( !str || str == "" ) return;
        if( sscanf(str,"%s(%s)×ßÁË¹ıÀ´¡£", tmp,name)==2 ) {
        name = lower_case(name);
        victim = present(name, environment(this_object()));
        if( !victim || victim->query("npc") || victim->query("no_attack")) return ;
        
        if( victim->query_level() > 5 && !victim->query("ghost") && victim->query("alignment") >100 ) {  
        
        if( !pointerp(attackers) || member_array(victim, attackers)==-1 ) {
        
        tell_object(victim,query("c_name")+"½ĞµÀ : Í¨Í¨È¥ËÀ°É£¬Í¬Ê±²»»³ºÃÒâµÄÍùÄãÕâÀï³å¹ıÀ´....\n");
         kill_ob(victim);
         } } }
        if( sscanf(str,"%sÍù%sÀë¿ª¡£", tmp,direction)==2) {
        if ( query_attacker() ) return ;
        hp1 = query("max_hp")/2;
        hitp = query("hit_points");
        if ( bleed = query("conditions/bleeding") || hitp < hp1  )        
        tell_room(environment(this_object()),
        "ÉßÈËÕ½Ê¿(warrior)ËµµÀ: µĞÈËÒÑ¾­ÌÓ×ßÁË£¬¿ìÀ´°ïÎÒÖÎÁÆ°É.....\n",this_object());
        return ;
        }  
}        
 