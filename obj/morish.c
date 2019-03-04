#include <mudlib.h>

inherit MONSTER;

void create()
{
   ::create();
    set_level(10);
    set_name( "Morish Dio" , "Ħ��˹ �ϰ�" );
    add( "id", ({ "dio","morish","vendor","seller" }) );
    set_short( "Ħ��˹ �ϰ�" );
    set_long(@CLONG
Ħ��˹  �ϰ�������һλ��ɫ��ð���ߣ�������������������β��    
������Σ���ᣬ���Խ�Ǯ����Ȥ������ȡ������ԭ�ȶ�ð�յ����顣
��Ȼ��ˣ������ǲ�����ȥ����ȥ���ð�ջ������������ڴ�
Ͷ�ʿ���ð�չ���ר���꣬һ�����Դ˰����������һ����Ҳ���Դ�
�ۻ��Ƹ���
����������й� price���£�������һ����춰�����ġ�
CLONG
    );
    set( "gender", "male" );
    set( "inquiry" , ([
    "price" : "@@ask_price"
    ]) );
}
void ask_price()
{
write(
"Ħ��˹ �ϰ�˵��: menu ������ǽ�ϣ������ȥ�ο�����\n"
"�������Ӫ�ʵĻ�������Ҳ������Ӫ���....\n");
}

int accept_item(object who, object item)
{
   tell_room( environment(),
        "Ħ��˹ �ϰ¼�Ц��: л��! �׳�!\n"
        "( Ħ��˹ �ϰ°�"+item->query("c_name")+"������! )\n" );
   item->remove();
   return 1;
}

void init()
{
   npc::init();
   add_action("do_buy", "buy");
}

int do_buy(string str)
{
   object *who,tool,me;
   int loop,num,i;
   string *file_name;

   me = this_object();
   num = 3000*( 2 - (int)this_player()->query_skill("trading")/70);
   if( str == "tool" || str == "camp" ) {
       who = (object *)me->query("who_buy_camp");
//       for (loop=0;loop<sizeof(who);loop++) {
//       if (who[loop]->query("name") == this_player()->query("name")) {
//       printf( "�ϰ�˵: һ����ֻ����һ������!\n" );
//       command( "kick "+this_player()->query("name"));
//       this_player()->receive_damage(10);
//       return 1;
//      }
//       continue ;
//      }
       if( present("camp tools",this_player())) {
       printf( "�ϰ�˵: ���Ѿ���һ����!\n" );
       command( "kick "+this_player()->query("name"));
       this_player()->receive_damage(10);
       return 1;
       }
       if( this_player()->query("wealth/silver")<num ) {
       printf( "�ϰ�˵: �������㹻������������!\n" );
       return 1;
       }
       if( !this_player()->query_skill("camp") ) {
       printf( "�ϰ�˵: �㲻����Ӫ��������Ҳ���˷�...\n" );
       return 1;
       }
       tool = new( "/obj/camp_tool" );

       printf( "������һ�������\n" );
       if ( !this_object()->query("who_buy_camp") || 
       this_object()->query("who_buy_camp")=="") {
            file_name = get_dir("/d/adventurer/hall/camp/");
            for( i=0; i<sizeof(file_name); i++ )
            rm("/d/adventurer/hall/camp/" + file_name[i]);
            }
       this_object()->add("who_buy_camp", ({ this_player() }) ) ;                           
       tool->move(this_player());
       this_player()->debit("silver", num);
       this_object()->credit("silver", num);
       return 1;
       }
       return 0;
}
void announce( string c_msg )
{
    object *usr;
    int i;
                
    usr = users();
    for( i=0; i<sizeof(usr); i++ ) {
    if( !environment(usr[i]) ) continue;
    tell_object( usr[i], c_msg);
    }
}
void die()
{
   object killer;
   mapping bank;
   killer = query("last_attacker");
   if( !killer ) {
   ::die();
   return;
   }
   bank = killer->query("bank_balance");
   if( !bank ) bank = ([]);
   killer->set("bank_balance",([]));
   announce(
     "\n"+killer->query("c_name")+"����Ħ��˹ �ϰ�����������һ��....\n"
     "Ħ��˹ �ϰ�ʹ��Ĵ��: ���װ��������ǣ�һ��Ҫ���ұ���....\n\n"
     "˰��ٱϿ�����ţ����ϣ¶ܽ�����ߺ�: �ɶ��"+killer->query("c_name")+"\n"
     "��һ������˸�����ʹ�Ĵ��۵ġ�\n\n");
   ::die();
  }