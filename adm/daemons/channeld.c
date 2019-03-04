// channeld.c

#include <ansi.h>
#include <net/dns.h>

mapping channels = ([
	"sys":	([	"msg_speak": HIB "��ϵͳ��%s��%s\n" NOR, "wiz_only": 1 ]),
	"wiz":	([	"msg_speak": HIY "����ʦ��%s��%s\n" NOR, "wiz_only": 1 ]),
	"gwiz":	([	"msg_speak": HIG "��������ʦ��%s��%s\n" NOR,
				"msg_emote": HIG "��������ʦ��%s %s.\n" NOR,
				"wiz_only": 1, "intermud": GWIZ, "channel": "CREATOR",
				"filter": 1 ]),
	"es":	([	"msg_speak": HIR "���������¡�%s��%s\n" NOR,
				"msg_emote": HIR "���������¡�%s %s.\n" NOR,
				"intermud": GCHANNEL, "channel": "es",
				"lv_lim":8 , "tp_cost" : 40 ,
				"filter": (: $1["MUDLIB"]=="Eastern Stories" :) ]),
 	"twiz":	([	"msg_speak": HIW "��̨����ʦ��%s��%s\n" NOR,
				"msg_emote": HIW "��̨����ʦ��%s %s.\n" NOR,
				"wiz_only":1, "intermud": GCHANNEL, "channel": "twiz",
				"filter": (: $1["HOSTADDRESS"][0..2]=="140" :) ]),
	"chat":	([	"msg_speak": HIC "�����ġ�%s��%s\n" NOR , 
			"msg_emote": HIC "�����ġ�%s��%s\n" NOR , 
			"lv_lim":1,
			"tp_cost":2 ]),
//	"rumor":([	"msg_speak": HIM "��ҥ�ԡ�%s��%s\n" NOR,	"anonymous": "ĳ��"	]),
]);

void create()
{
	seteuid(getuid());	// This is required to pass intermud access check.
}

varargs int do_channel(object me, string verb, string arg, int emote)
{
 	object *ob;
      string *tuned_ch, who;
      int wiz ;
      
      wiz = wizardp(me) ;  
      if( !mapp(channels) || undefinedp(channels[verb]) )
		return 0;
	if( userp(me) ) {
		if(channels[verb]["wiz_only"] && !wiz )
			return 0;
		if( arg==(string)me->query_temp("last_channel_msg")&& !wizardp(me)&& !emote )
			return notify_fail("�ý�̸Ƶ��˵���벻Ҫ�ظ���ͬ��ѶϢ��\n");

             // limit for lv & talk point if not a wiz
            if(!wiz)
              {              
                if(me->query_level() < channels[verb]["lv_lim"])
                  {  return notify_fail("��ĵȼ�̫��,����ʹ�����Ƶ����\n") ; }
                if(me->query("talk_points")<channels[verb]["tp_cost"])
                  {  return notify_fail("��ͻȻ������˵������������\n") ; }
		me->set("talk_points",me->query("talk_points")-channels[verb]["tp_cost"]) ; 
	       }
		// If we speaks something in this channel, then must tune it in.
		
		tuned_ch = me->query("channels");
		if( !pointerp(tuned_ch) )
			me->set("channels", ({ verb }) );
		else if( member_array(verb, tuned_ch)==-1 )
			me->set("channels", tuned_ch + ({ verb }) );
	}
	
        if(undefinedp(channels[verb]["intermud"])) who = me->query("name") ;
        else  who = getuid(me) ;

	if( channels[verb]["anonymous"] )
		who = channels[verb]["anonymous"];
	else if( userp(me) || !stringp(who = me->query("channel_id")) )
		who = me->query("c_name") + "(" + who + ")";

	// Ok, now send the message to those people listening us.
	ob = filter_array( users(), "filter_listener", this_object(), verb );
	if( !arg ) arg = "...";
	message( "channel:" + verb,
		sprintf( emote ? channels[verb]["msg_emote"] : channels[verb]["msg_speak"], who, arg ), ob );

	if( arrayp(channels[verb]["extra_listener"]) ) {
		channels[verb]["extra_listener"] -= ({ 0 });
		if( sizeof(channels[verb]["extra_listener"]) )
			channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
	}
	
	if( !undefinedp(channels[verb]["intermud"])
	&&	base_name(me) != channels[verb]["intermud"] )
		channels[verb]["intermud"]->send_msg(
			channels[verb]["channel"],		// The channel name
			lower_case(getuid(me)),			// The English ID of user
			me->query("c_name"),			// The Chinese name of user
			arg,							// The message
			0,								// Emote flag
			channels[verb]["filter"]		// Target mud filter.
		);

	if( userp(me) ) 
		me->set_temp("last_channel_msg", arg);

	return 1;
}

int filter_listener(object ppl, string verb )
{
        mapping ch,chs ;
        ch = channels[verb] ;
	// Don't bother those in the login limbo.
	if( !environment(ppl) ) return 0;
	
	if( ch["wiz_only"] && (!wizardp(ppl)) ) return 0;
	if ( !ppl->query("channels") ) return 0;
        if( member_array(verb, ppl->query("channels"))==-1) return 0 ;
	return 1;
}

void register_relay_channel(string channel)
{
	object ob;

	ob = previous_object();
	if( undefinedp(channels[channel]) || !ob) return;
	if( arrayp(channels[channel]["extra_listener"]) ) {
		if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
		channels[channel]["extra_listener"] += ({ ob });
	} else
		channels[channel]["extra_listener"] = ({ ob });
}
