#include <mudlib.h>

inherit OBJECT;
int in_use;

void init()
{
	add_action( "light_pastil", "light" );
}

void create(){

	set_name("pastil","�¶��ĳ���");
	set_short("�¶��ĳ���");
	set_long(@C_LONG
�¶������ƹ���ؼ�һ�е�����,��սʿ��������ػ���...
���¶��ĳ��㡻�Ǵ��˾��������¶����������,�Ǽ����������Ʒ
�ഫ��ȼ(light)�����˿��Եõ������ף��,����ޱȵ�����...
C_LONG
                 );
        set("value" , ({10,"silver"}) );
        set("weight",10);
	set("unit","��");
}

int light_pastil(string arg)
{
        if( arg != "pastil") return 0;
        if (!in_use)
       {  
        in_use =1;
        
	set("prevent_drop",1); 
        set_short("һ����ɫ����������������"); 

	write( 
"���ȼ�������¶�����ĳ��㣬һ����ɫ����������ס������壬������Լ���ǿ�� \n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"��ȼ��һ�����㣬ͻȻ������¶��������Ӱ����ס����������\n",
		this_player() );
 
	this_player()->modify_stat("armor_class",10);
	call_out("restore",30,this_player());
	return 1;
        }
}

void restore(object player){

	tell_object(player, "����ס�������������������ɢ��...\n");
	this_player()->modify_stat("natural_armor_class",-2);
        remove(); 
}
