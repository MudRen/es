#include "../takeda.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Silver Dragon","Òø¼×ÉñÁú" );
	add ("id", ({ "dragon" }) );
	set_short( "dragon","Òø¼×ÉñÁú");
	set("unit","Î²");
	set_long(@C_LONG
ÕâÊÇÒ»ÌõÓÐÖøÃÀÀöÒøÉ«ÁÛ¼×µÄ¾ÞÁú£¬±³ÉÏÓÐÖø¾Þ´óÇÒÈñÀûµÄ±³¼×
ÔÚ´«ËµÖÐËüÊÇ¾ßÓÐ²»¿ÉË¼ÒéÁ¦Á¿µÄÉÆÁ¼ÁéÊÞ£¬ÈÎºÎÎäÆ÷Ö»Òª½þÈëËüµÄÏÊÑª
¾Í¿ÉÒÔÌáÉýÎäÆ÷Á¦Á¿Êý±¶¡£¾ÝËµºÜ¾ÃÒÔÇ°ÓÐ¸ö½ÐÀ×Ë¼µÄÎäÊ¿ÔøµÃµ½ËüµÄÑª
¶øÖÆ³ÉÁúÑªÇ¹¡£
C_LONG	   
	);
	set( "likefish",1);
	set( "unbleeding",1);
	set("alignment",2700);
	set("max_hp",800);
	set ("time_to_heal", 1);
	set("hit_points",800);
	set_perm_stat("str", 30 );
	set_perm_stat("dex", 23 );
	set_perm_stat("kar", 25 );
	set_skill("dodge",100);
	set_natural_weapon( 80, 45, 72 );
	set_natural_armor( 130,60 );
	set ("gender", "male");
	set ("race", "monster");
	set_c_limbs(({"¼áÓ²µÄ±³²¿","Ç°¾±","´Ö´óµÄ³¤Î²","Í·²¿"}));
	set_c_verbs( ({"%s»ÓÎèÁú×¦×¥Ïò%s","%sÁúÒ÷Ò»Éù£¬ÁúÎ²¿ñÉ¨Ïò%s",
	"%sÕÅ×ì£¬Ò»µÀ»ð¡õÅçÏò%s"}));
        set ("tactic_func","special_attack");
        set( "inquiry", ([
              "laice" : "@@ask_laice",
              "blood" : "@@ask_blood",
              "dragon" : "@@ask_dragon",
              "snake" : "@@ask_snake",
              "help" : "@@ask_help",
              "chiyu" : "@@ask_chiyu",
              "ò¿ÓÈ" : "@@ask_chiyu",
              ]));
}
void ask_laice()
{
write (
      "Òø¼×Õ½ÁúÍ»È»ºÜÉúÆøµÄÑù×Ó£¬ÂîµÀ: ÄÇ¸ö¸ÃËÀµÄ¼Ò»ï£¬ËµºÃÒª°ïÖúÎÒµÄ£¬\n"
      "µ±ÎÒÓÃ×Ô¼ºµÄÑª(blood)Ç¿»¯ËûµÄÎäÆ÷áá£¬Ëû¾Í²»ÖªËù×ÙÁË?\n");
      return ;
}

void ask_blood()
{
      write (
      "Òø¼×Õ½ÁúËµµÀ: ×Ô´ÓÉÏ´Î±»À×Ë¼Æ­¹ýÖ®áá£¬ÎÒÔÙÒ²²»°ïÖúÈÎºÎÈËÁË£¡\n"
      "ÏëÒªÎÒµÄÑª£¬³ý·Ç°ÑÎÒÉ±ÁË£¬ÄãÒªÓÐÐËÈ¤¾ÍÀ´°É....\n"
      "ËµÍê£¬Òø¼×Õ½ÁúÓÃ±Ç×ÓÏòÄãÁ³ÉÏ´µÆø¡£\n");
      return ;
}
void ask_dragon()
{
      write (
      "Òø¼×Õ½ÁúËµµÀ: ÁúÊÇÕâÊÀ½ç×îÇ¿´óµÄÉúÎï....ÎÒµÄ×æÏÈ¾ÍÊÇ´«ËµÖÐµÄÓ¦Áú...\n"
      "ËüÔø°ïÖú»ÆµÛ´ò°Üò¿ÓÈ...\n" );
      return ;
}
void ask_snake()
{
      write (
      "Òø¼×Õ½ÁúËµµÀ: Äã¼û¹ýÄÇÌõÀÃÉßÂð? ËûÊÇ´«ËµÖÐò¿ÓÈµÄÊÖÏÂ¾ÅÓ¤µÄáá´ú¡£\n");
      return ;
}

void ask_help()
{
      write("ÎÒ¸ÃÏàÐÅÄãÂð? Òø¼×Õ½Áú»³ÒÉµÄ¿´ÖøÄã......\n");
      call_out("ask_help2",10,this_player());
      return ;
}
void ask_help2()
{
      if ( this_player()->query("alignment") > 0 ) {
      write(@C_LONG
Òø¼×Õ½ÁúËµµÀ: ºÃ°É£¬¿´ÄãÒ²²»Ïñ¸ö»µÈË£¬ÎÒ¾Í¹ÃÇÒÏàÐÅÄã°É...
´«ËµÖÐò¿ÓÈ(chiyu)ÔÚÍÍÂ¹Õ½ËÀÖ®áá£¬ËûµÄÊÖÏÂ¾ÅÓ¤ÌÓµ½Õâ¸öÉ½¶´£¬
ÃØÃÜ½øÐÐÈÃò¿ÓÈ¸´»îµÄÒõÄ±£¬¶ø±»ÎÒ×æÓ¦Áú·¢ÏÖÁË£¬ì¶ÊÇËüÒ²½øÈëÕâ
¸öÉ½¶´²¢ÔÚÕâ¶ù²¼ÏÂ½á½çÒÔ°µµØ½øÐÐÆÆ»µµÄÈÎÎñ£¬²¢½«Õâ¸öÈÎÎñ´«³Ð
¸øËüµÄ×ÓËïÃÇ¡£
C_LONG
            );
            call_out("ask_help3",10,this_player());
            return ;
            }
      write("ÄãÊÇ»µÈË£¬Ò»¶¨ÊÇÄÇÖ»ÀÃÉßµÄÊÖÏÂ....¿ì¹ö¿ª.....\n"
            "ËµÍê×÷ÊÆÓûÆË.....\n");
            return ;
}
void ask_help3()
{
       write(@C_LONG
Õâ÷á¶àÄêÀ´£¬ÓÉì¶ÎÒµÄ×æÏÈÃÇµÄÅ¬Á¦£¬ÄÇÐ©Ð°¶ñµÄ¶«Î÷Ê¼ÖÕÃ»ÄÜÕÒµ½
Ê¹ò¿ÓÈ¸´»îµÄ¹Ø¼üÎï£­[ ò¿ÓÈµÄÒÅº¡ ]£¬µ«×î½üÎÒÎÞÒâÖÐµÃÖª£¬Ä¿Ç°¾ÅÓ¤      
µÄáá´ú¾ßÓÐ¼«Ç¿µÄºÚÄ§·¨ÄÜÁ¦£¬¶øËüÄ¿Ç°ÕýÔÚ¿ª·¢Ç¿Á¦µÄ¶¨Î»ËÑÑ°Ä§·¨¡£
ÈôÊÇ±»Ëü¿ª·¢³É¹¦£¬²»Ö»ÎÒÃÇÕâÀïÓÐÎ£ÏÕ£¬¸ü¿ÉÄÜ±»ËüÏÈ·¢ÏÖò¿ÓÈµÄÒÅº¡
µ½Ê±Èôò¿ÓÈ¸´»î£¬ÕâÊÀ½ç¾ÍÍêÁË....
C_LONG
       );
             call_out("ask_help4",10,this_player());
             return ;
}
void ask_help4()
{
        write(@C_LONG
Ä¿Ç°µÄµ±ÎñÖ®¼±ÊÇ£¬ÔÚËüÃÇ¿ª·¢³ö¶¨Î»ËÑÑ°Ä§·¨Ç°£¬ÏÈÕÒµ½ò¿ÓÈµÄÒÅº¡
²¢ÇÒ´øµ½ÎÒÕâÀïÀ´£¬Èç¹ûÄãÄÜ×÷µ½Õâ¼þÊÂ£¬ÎÒ½«»á¾¡ÎÒËùÄÜµÄ»Ø±¨Äã
Ç§Íò²»ÒªÊÔÖøÌôÕ½ÄÇÖ»´óÉß£¬Èç¹ûÄã°ÑËüÏûÃðµô£¬Õâ¸ö¶´¿ÉÄÜ»á·¢ÉúÎ£ÏÕ
¶øÕâ»áÊ¹ÎÒÊ§È¥ÁË×·×ÙËüÃÇµÄÏßË÷....
ÄãÌýÁËËüµÄ»°£¬ÐÄÀïÓÐµãÏë°ïÖúËü£¬µ«ÓÖ²»ÖªÊÇ·ñÊÊµ±
²»¹ÜÔõ÷áËµ£¬ÏÈ»ØÈ¥±¨¸æ¹«ËïÏÈÉúÄãµÄ·¢ÏÖËÆºõ±È½ÏÇ¡µ±...
C_LONG
              );
        this_player()->set_temp("find_something",1);
        return ;
}              
void ask_chiyu()
{
write("ò¿ÓÈÊÇÉÏ¹ÅÊ±µÄ´óÄ§Í·£¬ÎªÁËÕù¶áÌìÏÂµÄ°ÔÈ¨£¬Óë»ÆµÛ´óÕ½ì¶ÍÍÂ¹Ö®Ò°¡£\n"
      "¶øÕâ¸½½ü¾ÍÊÇ¹ÅÊ±ºòµÄÍÍÂ¹....\n");
      return ;
}
void die()
{  
   object ob1,killer;
   
   killer = query("last_attacker");
   ob1 = killer->query("weapon1");
   if( !killer ) {
     ::die();
     return;
   }
   if( !ob1 ) {
     ::die();
     return;
   }
   tell_room(environment(this_object()),
      killer->query("c_name")+"Ò»Éù´óºð£¬½«ÊÖÖÐµÄ"+ob1->query("c_name")+"ÏòÒø¼×Õ½ÁúÓÃÁ¦²åÈ¥...\n"+
      "\nÒø¼×Õ½Áú¿ñºð²»ÒÑ£¬Â¡Â¡Ö®Éù²»¾øì¶¶ú£¬×ªÍ·¶Ô"+killer->query("c_name")+"·¢³öËüÁÙÖÕÒ»»÷ £¡\n\n\n");
      killer->set("hit_points",10);
      "/d/magic/magic"->report( this_object(), killer );
   tell_room(environment(this_object()),
      "¾¡Á¦Ò»»÷áá£¬Õ½ÁúÖÕì¶²»Ö§£¬ÍÂÑªµ¹µØ¶øÍö....\n"+
      killer->query("c_name")+"½«²åÔÚÕ½Áú¡õÌåÉÏµÄ"+ob1->query("c_name")+
      "°Î³ö£¬Ë³ÊÖ°ÑÉÏÃæµÄÑª¼£²ÁÊÃÇ¬¾»¡£\n"      
      );
   ob1->add( "min_damage",5 );
   ob1->add( "max_damage",5 );
   ::die();   
}
void announce( string msg, string c_msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
		tell_object( usr[i], can_read_chinese(usr[i])? c_msg: msg );
	}
}
       
       
int special_attack()
{// 10% use it! damage 30-50.
    object env,*inv,*victim;
    int i;
    env=environment(this_object());
    inv=all_inventory(env);
    if(random(10)<8) return 0;
    tell_room( environment( this_object() ), 
      "\n\n [1;41m ÒøÁúÅç³öÒ»ÍÅÖËÈÈÁ¶»ð£¬ÉÕµÃËùÓÐÈËÈç´¦ì¶Á¶Óü°ã£® [0;40m \n\n\n" ,
      this_object()
    );
    this_object()->receive_healing(10);
    i = sizeof(inv);
    while(i--) {
      if (inv[i]!=this_object()) 
        {
           inv[i]->receive_special_damage("fire",random(20)+30);
           "/d/magic/magic"->report( this_object(), inv[i] );
        }
    }
    return 1;
}

