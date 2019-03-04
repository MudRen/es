// all functions do firse when the player enter ES, added by Kyoko.
// Added Chinese by Annihilator.
#include <body.h>
#include <logs.h>
#include <uid.h>
#include <config.h>
#include <daemons.h>
int check_money(object player)
{
	int money,bank_money,max_money;
	if ( !player ) return 1;
	money = player->total_wealth() ;
	bank_money = (int)player->query("bank_balance/gold")*100+
				 (int)player->query("bank_balance/silver")*10+
				 (int)player->query("bank_balance/platinum")*1000+
				 (int)player->query("bank_balance/copper");
	max_money = 3000000 ;
	if ( (money+bank_money) > max_money ) {
		player->delete("wealth");
		if ( bank_money > max_money ) {
			player->delete("bank_balance");
			player->set("wealth/silver",max_money/10);
		} else 
		player->set("wealth/silver",(max_money-bank_money)/10 ) ;
		tell_object(player,"\n\n�� ! ��Ǯ̫��� !! \n");
	}
	return 1;
}
int check_make_up(object player)
{
	string real,c_real;
	if ( !player || nullp(player) ) return 1;
	if ( !player->query("make-up") ) return 1;
	real = player->query("org_name");
	c_real = player->query("c_org_name");
	if ( !real || !c_real ) return 1;
	player->set("id", ({ real }) );
	player->set("name",real);
	player->set("c_name",c_real);
//	player->set("c_cap_name",c_real);
	player->set("title",player->query_title());
	player->set("make-up",0);
	return 1;
}
int compare_okip(object player)
{
    string *ip_list, cur_ip, cur_ip_num, ip_part, num_part, be_checked;
    int i, gate, nothing=1, len, ed;
    
	if ( !player ) return 0;
    if( !((string)player->query("ok_ip")) ) {
	  tell_object(player, 
	  	"[OKIP]: ��û���趨�κ� IP Address ��飡���� okip ָ���趨��\n");
	  return 1;
	}
	ip_list = explode((string)player->query("ok_ip"),":");
	cur_ip = query_ip_name(player);
	cur_ip_num = query_ip_number(player);
	for(i=0; i<sizeof(ip_list); i++) {
      if(ip_list[i] == "") continue;
      nothing = 0;
	  if(sscanf(ip_list[i],"%s*", be_checked)==1 && be_checked != "" ) {
		len = strlen(be_checked);
		ip_part = extract(cur_ip, 0, len-1);
		num_part = extract(cur_ip_num, 0, len-1);
	  } else if(sscanf(ip_list[i],"*%s", be_checked)==1 && be_checked != "" ) {
		len = strlen(be_checked);
		ed = strlen(cur_ip);
		ip_part = extract(cur_ip, ed-len); /* Elon fix this line */
		num_part = extract(cur_ip_num, ed-len);
	  } else {
	    be_checked = ip_list[i];
	    ip_part = cur_ip;
	    num_part = cur_ip_num;
	  }
	  if( lower_case(be_checked) == lower_case(ip_part) ||
	      lower_case(be_checked) == lower_case(num_part) ) {
		tell_object(player, " IP checked and ok.\n");
		return 1;
	  }
	}
	if( nothing ) {
	  tell_object(player, 
	  	"[OKIP]: �� IP Address ���ơ�\n");
	  return 1;
	} else return 0; 
}

void check_okip(object player)
{
	// Check okip....	
	// check money first :P)
	if ( ENABLE_MONEY_CHECK ) 
		check_money(player);
    if( ENABLE_OKIP_CHECK ) {
      tell_object(player,
      	"\n��� IP Address ��...  ");
      if( !compare_okip(player) ) {
      	if ( !player ) return;
      	player->set("okip_fail", ({ player->query("ip"), time() }) );
	    tell_object(player,
	      "\nWARNING: You are not supposed to be from this IP!\n");
#ifdef OKIP_CRACKER_LOG
        seteuid(ROOT_UID);
 	    log_file(OKIP_CRACKER_LOG,"************\n"+
 	      (string)player->query("name") + " tried to login from " +
 	      (string)player->query("ip") + " but failed AT " +
 	      extract(ctime(time()),4,15) + "\n"
 	    );
#endif /* OKIP_CRACKER_LOG */
        tell_object(player, "The Gods of ES force you: quit.\n");
        player->quit();
      }
    } else
      tell_object(player, "No OKIP checking!\n");    
}

void check_spouse(object player)
{
    string name ;
    object spouse ;
    
    if (!player) return;
    if(!name = (string)player->query("spouse")) return ;
    
    if(!spouse = find_player(lower_case(name)) ) return ;
    
    tell_object(player,"\n�����һ����������,������������Ĭ��.��\n") ;
    tell_object(spouse,"\n�����һ��ص����������, ������ȥ����.��\n") ;

    return ;
}


// add by elon to do status check on player with obnormal(?) data

void check_stats(object player)
{
    if (!player) return;
    if(wizardp(player)) return; // skip wiz check
    if((player->query_perm_stat("str")>=26) ||
       (player->query_perm_stat("int")>=28) ||
       (player->query_perm_stat("con")>=28) ||
       (player->query_perm_stat("pie")>=26) ||
       (player->query_perm_stat("kar")>=26) ||
       (player->query_perm_stat("dex")>=28) ||
       (player->query("spell_levels/black-magic")>60) ||
       (player->query("spell_levels/elemental")>60) ||
       (player->query("thief_level/backstab")>60) ||
       (player->query("experience")>player->query("age")*100))
    {
	seteuid(ROOT_UID);
	log_file("data.x",
	(string)player->query("name")+" : "+
	(string)player->query("ip")+" @ "+
	(string)ctime(time())+"\n");
	tell_object(player,"��ĵ���������... ��֪ͨ��ʦ.....\n");
	player->quit();
	return;
    }
    // add any more extra check here
    return ;
}

