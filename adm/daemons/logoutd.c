// leave_d is called after a user quit from ES. It moves
// other players in chat room to open area
// Create by Iris@Eastern.Stories 95/12/23

#include <body.h>
#include <logs.h>
#include <uid.h>
#include <config.h>
#include <daemons.h>
#include <player.h>
#include <login.h>

mapping options;

int enter_one();
int enter_world(object player);

int create()
{
	seteuid(ROOT_UID);
}

int call_other_player()
{
	object chat_room,NETDEAD;
	object* all_chat_user;
	object* urs;
	int i, allow;
	
	chat_room=find_object_or_load(IRC_CHAT_ROOM);
        NETDEAD = find_object_or_load("/d/std/rooms/netdead");
        all_chat_user=all_inventory(chat_room);
        if (! all_chat_user) {
        	log_file("iris.debug","set_chat_room off for no one in chat room\n");
        	"/adm/daemons/logind"->set_chat_room(0);
        	return 1; /*no body in chat room */
        }
        urs = filter_array(users()+all_inventory(NETDEAD), "check_players",
                     this_object(),all_chat_user );
        options = DEFAULT_LOGIN_OPTIONS;             
        if ( ( allow =  options["MAX_USERS"] - sizeof(urs) ) > 0 ) {
           for ( i = 0 ; i < allow ; i ++ ) 
           	enter_one();
        }   
}

int check_players(object user)
{
        if ( !user->query("user") ) return 0;
        if( !environment(user)
          || ( environment(user) == find_object(IRC_CHAT_ROOM) )
          || user->query_temp("chat_room")
          || wizardp(user))
          return 0;
        return 1;
}

int enter_one() 
{
	object chat_room;
	object* all_chat_user;
        int i, small, small_time;
        small = 0;
        small_time = time();	
        
	chat_room=find_object_or_load(IRC_CHAT_ROOM);
	all_chat_user=all_inventory(chat_room);
	if (sizeof(all_chat_user)==0) {
        	"/adm/daemons/logind"->set_chat_room(0);
		return 1;
	}	
        for (i=0; i< sizeof(all_chat_user); i++) {
        	if (userp(all_chat_user[i])&&(!wizardp(all_chat_user[i]))) {
        		if (!all_chat_user[i]->query_temp("chat_user"))
        			all_chat_user[i]->set_temp("chat_user",time());
        		if (all_chat_user[i]->query_temp("chat_user")<small_time) {
        			small_time=all_chat_user[i]->query_temp("chat_user");
        			small=i;
        		}	
        	}
	}
	if ( userp( all_chat_user[small] ) ) enter_world(all_chat_user[small]); 
	else "/adm/daemons/logind"->set_chat_room(0);
	return 1;       
}

int enter_world (object player)
{
	player->delete_temp("chat_user");
	player->delete_temp("be_sucked");
	player->delete_temp("be_clawed");
	player->delete_temp("be_hoofed");
	player->set_heart_beat(1);
	tell_room(environment(player),"���ϴ���һ�����������: "+
	          player->query("c_name")+" ������ȥ����.��\n");
	player->move("/d/adventurer/hall/adv_guild");
	tell_object(player,"��е�һ����ѣ, һ�ſ������ܵľ�ɫ�Ѿ�����.��\n");
}                                                
