#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(5);
   set_name( "ru - hua", "如花" );
   add( "id", ({ "girl", "liang" }) );
   set_short( "如花" );
	set_long(@C_LONG
你看到一位容貌丑恶, 满脸麻子的女孩。你想还是快点离开吧!
C_LONG
	);
	set( "race", "human" );
	set( "gender", "female" );
   set( "alignment", -50 );
   set_perm_stat( "int", 8 );
   set_perm_stat( "dex", 6 );
   set_perm_stat( "kar", 3 );
   set_skill( "dodge", 50 );
   set( "wealth/copper", 10 );
	set_natural_weapon( 4, 4, 4 );
   set_natural_armor( 35, 6 );

   set( "chat_chance", 15 );
   set( "chat_output", ({
        "如花轻声道: 色狼怎麽还不走?\n"
        }) );
}

int stop_attack()
{
   object mother, *tmp;

   mother = present( "mother", environment() );
   if( !mother ) return 0;
   tell_room( environment(),
             "梁母怒喝: 没良心的家伙, 竟敢欺侮我的宝贝! 去死吧!\n" );
   tmp = query_temp( "protectors" );
   if( !tmp || member_array( mother, tmp )==-1 ) {
        add_temp( "protectors", ({ mother }) );
        mother->add_temp( "protectees", ({ this_object() }) );
        }
        tmp = mother->query_attackers();
   if( !tmp || member_array( this_player(), tmp )==-1 )
        mother->kill_ob( this_player() );
}

void relay_message(string class1, string msg)
{
        string who, str;

        if( sscanf( msg, "%s(%s)走了过来。", str,who )==2 )
            tell_room( environment(this_object()), 
                "\n如花惊叫道: 色狼来了!!\n\n" );
        return ;
}
