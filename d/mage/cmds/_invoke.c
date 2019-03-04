//#pragma save_binary
// create by Kyoko.
#include <mudlib.h>

inherit DAEMON ;

int help() ;

int invoke_on()
{
    int skill, wc;
    object weapon;
    weapon = this_player()->query("weapon1");
    if( !weapon )
      write("������в�û��װ���κ�������\n" );

    else if( !weapon->query("max_charge") )
      write("�����ϵ�����û���κ����⹥����������\n" );
    else if( weapon->query("power_on") )
      write("�����ϵ�������Ϳ����ͷ����⹥��������\n" );

    else {
      skill = (int)this_player()->query_skill("invoke");
      wc = (int)weapon->query("weapon_class");
      if( wc > 10 && skill < wc*2 )
        write("��ļ��ܲ����Կ����ͷ������������⹥��������\n" );

      else {
        write("��ɹ��ؿ����ͷ������������⹥�������ˡ�\n" );

        weapon->set("power_on", 1);
      }
    }
    return 1;
}

int invoke_off()
{
    int skill, wc;
    object weapon;
    weapon = this_player()->query("weapon1");
    if( !weapon )
      write( "������в�û��װ���κ�������\n" );

    else if( !weapon->query("max_charge") )
      write("�����ϵ�����û���κ����⹥����������\n" );

    else if( !weapon->query("power_on") )
      write("�����ϵ�������͹ر��ͷ����⹥��������\n" );

    else {
      skill = (int)this_player()->query_skill("invoke");
      wc = (int)weapon->query("weapon_class");
      if( wc > 10 && skill < wc*2 )
        write("��ļ��ܲ����Թر��ͷ������������⹥��������\n" );

      else {
        write("��ɹ��عر��ͷ������������⹥�������ˡ�\n" );

        weapon->set("power_on", 0);
      }
    }
    return 1;
}

int cmd_invoke(string str)
{
        if( !str ) return help();
		switch(str) {
			case "on"      : return invoke_on();
			case "off"     : return invoke_off();
			default : return help();
		}
}

int help()
{
		write( @C_HELP
ָ���ʽ: invoke <on|off>

��ָ����Խ�������װ����ħ�����������⹥�������ͷŻ��Ƿ�ӡ��

C_HELP
		);
    return 1;
}
