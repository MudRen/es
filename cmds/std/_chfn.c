//#pragma save_binary

// This is part of the TMI distribution mudlib.
// Please retain this header if you use this code.
// Coded by Sulam (12-8-91)
// Fixed to accept defaults correctly by Jubal (Dec15/91)
// Help added by Brian (1/27/92)
// Revised by Buddha for new variable access (6-21-92)
// Fixed a typo (posted by Bonzo) (6-3-93)  Fix put in by Guile
// Added Chinese name by Annihilator (12-14-93)

#include <mudlib.h>
#include <protects.h>
#include <ansi.h>

inherit DAEMON;

object link;
int chinese_mode;

int cmd_chfn( string arg )
{

	if((string)this_player()->query("name") == "guest") {
		write("请输入你的英文名字：");
		input_to( "guest_name" );
		return 1;
	}

	link = this_player()->query_link();

		write( @TEXT
修改人物背景资料:
______________________________________________________________
在 [] 里的是每项资料的预设值，如果你要使用预设值，直接按 ENTER
键即可。

TEXT
		);
		printf("%s [%s] : ","真实姓名",(string)link->query("real_name"));

	input_to("new_name");
	return 1;
}

protected void guest_name(string rname)
{
	if( rname && strlen( rname ) > 0 ) {
		this_player()->set( "id", ({ rname, "guest" }) );
		this_player()->set("guest_name", rname );
//		this_player()->set("cap_name", "Guest, " + capitalize(rname) );
	}
	printf( "%s [%s] : ","中文姓名",(string)this_player()->query("c_name"));
	input_to("guest_chinese_name");
}

protected void new_name(string rname)
{
	if( rname && strlen( rname ) > 0 ) {
		link->set("real_name", replace_string(rname,ESC,""));
          link->set("real_name", replace_string(rname,CSI,""));
		link->save_data() ;
	}
	printf( "%s [%s] : ","中文姓名",(string)link->query("c_name"));
	input_to("new_chinese_name");
}

protected void new_chinese_name(string ncname)
{
	string tmp1,tmp2;
	if( !ncname || ncname == "" ) ncname = link->query("c_name");
	if( ncname && strlen( ncname ) > 0 ) {
	        if(this_player()->query("make-up"))
	          {
	                write("请先脱掉面具再改名字喔\n") ;
	              return ;
	           }
		if( (member_array(ncname, PROTECT_C_NAME) != -1) &&
			!member_group(geteuid(this_player()),"admin") ) {
			write("对不起，因为某种原因，你不能用这名字，请另外想一个吧。\n");
			printf( "%s [%s] : ","中文姓名",(string)link->query("c_name"));
			input_to("new_chinese_name");
			return;
		}
		if( sscanf(ncname,"%s(%s",tmp1,tmp2)==2) {
			write("对不起，名字中不能含有括号。\n");
			printf( "%s [%s] : ","中文姓名",(string)link->query("c_name"));
			input_to("new_chinese_name");
			return;
		}
		if( strlen( ncname ) > 14 ) {
			write( "对不起，你的中文名字太长了，请控制在 7 中文字以内。\n");
			printf( "%s [%s] : ","中文姓名",(string)link->query("c_name"));
			input_to("new_chinese_name");
			return;
		}
//		if( ncname[0]>='a' && ncname[0]<='z' )
			ncname = replace_string(ncname,ESC,"");
			ncname = replace_string(ncname,CSI,"");
		link->set("c_name", ncname);
		this_player()->set("c_name", ncname);
		this_player()->set("title",this_player()->query_title(this_player()));
		link->save_data();
	}
        printf( "%s [%s] : ","电子邮件地址",link->query("email"));
	input_to("new_email");
}

protected void guest_chinese_name(string ncname)
{
	if( !ncname || ncname == "" ) ncname = link->query("c_name");
	if( ncname && strlen( ncname ) > 0 ) {
	        if(this_player()->query("make-up"))
	          {
	                write("请先脱掉面具再改名字喔\n") ;
	              return ;
	           }
		if( (member_array(ncname, PROTECT_C_NAME) != -1) &&
			!member_group(geteuid(this_player()),"admin") ) {
			write(
				"对不起，因为某种原因，你不能用这名字，请另外想一个吧。\n");
			printf( "%s [%s] : ","中文姓名",(string)link->query("c_name"));
			input_to("new_chinese_name");
			return;
		}
		if( strlen( ncname ) > 14 ) {
			write("对不起，你的中文名字太长了，请控制在 7 中文字以内。\n");
			printf( "%s [%s] : ","中文姓名",(string)link->query("c_name"));
			input_to("new_chinese_name");
			return;
		}
//		if( ncname[0]>='a' && ncname[0]<='z' )
		ncname = replace_string(capitalize(ncname),ESC,"");
		ncname = replace_string(capitalize(ncname),CSI,"");
		this_player()->set("c_name", ncname);
		this_player()->set("title",this_player()->query_title(this_player()));
	}
}

protected void new_email(string e)
{
	if( e && strlen( e ) > 0 ) {
		link->set("email", replace_string(e,ESC,""));
		link->save_data() ;
	}
}

int help() {
	write(@HELP
指令格式: chfn

这个指令可以让你重新设置自己的背景资料。

HELP
);
	return 1;
}
/* EOF */
