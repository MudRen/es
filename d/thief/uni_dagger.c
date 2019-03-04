//#pragma save_binary
#include <mudlib.h>
#include "/d/thief/thief.h"

inherit GUILD_OB;

inherit WEAPON;

void create()
{
	guild_ob::create();
	seteuid(getuid());
	set_class_name("thief");
	if (clonep(this_object())) {
		set_default_ob(__FILE__);
		return ;
	}
	set_name("universal dagger", "����С��");
	add("id",({ "dagger" }) );
	set_short("����С��");
	set_long(@LONG
����һ��С͵ר�õĶ���;ߡ��С��������������������ǽ�졢��Ǯ���ȵ�
����Ȼ���������������ۣ�������һ���о����С͵���У�ȴ���Գ�Ϊ����
ı���Ĺ��ߡ���������� help dagger �Ի�ý�һ����˵����
LONG
	);

	set( "unit", "��" );
    	set( "weapon_class", 9 );
    	set("type","dagger");
    	set( "min_damage", 4 );
    	set( "max_damage", 8 );
	set( "weight", 5 );
	set( "extra_look", "$N����С͵ר�õ�����С����\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_fellows", "thieves");
	add_action("do_chat", "whisper");
}

int do_fellows()
{
//	return guild_ob::list_guild_members();
        object *usr;
        int i,guild_lv;

        usr = filter_array( users(), "filter_members", this_object() );
        usr = sort_array( usr, "sort_members", this_object() );
        if( sizeof(usr) ) {
                owner->quick_message(
          "Ŀǰ���� " + sizeof(usr) + " λ"+to_chinese(class_name)+"������:\n"
                        + "==================================\n");
             for( i=0; i<sizeof(usr); i++ ) {
		
		guild_lv = ( (int)usr[i]->query("thief_level/backstab") +
			     (int)usr[i]->query("thief_level/throw-dagger") ) /2;
		if ( wizardp(owner) && (int)usr[i]->query("make-up") == 1 )
                    owner->quick_message(
			sprintf( "[ %2d | %2d ] %s (%s) [�� %s װ��] \n",
			usr[i]->query_level(),guild_lv,
			usr[i]->query("short"),
			capitalize(usr[i]->query("name")) ,
			capitalize(usr[i]->query("org_name")) 
		    ));
		else 
                    owner->quick_message(sprintf( "[ %2d | %2d ] %s (%s) \n",
                        usr[i]->query_level(),guild_lv,
                        usr[i]->query("short"), 
			capitalize(usr[i]->query("name")) 
		    ));
	    }
        } else
                owner->quick_message(
                        "�ƺ�û���κ�"+to_chinese(class_name)+"����ĳ�Ա������.
...��\n");
        return 1;
}

// The guild channel
int do_chat(string arg)
{
	if( !arg )
		return notify_fail("���������С͵ͬҵ˵ʲ�᣿\n");
	return guild_ob::guild_line(arg);
}

int info(string arg)
{
	switch(arg) {
		case "history": cat( GUILD_DATA+"c_thief_history" );
			break;
	    case "commands": cat( GUILD_DATA+"c_thief_commands" );
			break;
		case "topics":
		default: 
write( @C_TOPICS
С͵������һ�������ԺܸߵĹ��ᣬ������� info ָ��ȡ���й����������
������Ѷ:
    history    - �й�С͵�������ʷ��
    commands   - �й�С͵��ʹ�õ�����ָ�
    
C_TOPICS
			);
			break;
	}
	return 1;
}

int help(string arg)
{
	if( !arg || arg!="dagger" ) return 0;
	cat(GUILD_DATA+"c_uni_dagger");
	return 1;
}
