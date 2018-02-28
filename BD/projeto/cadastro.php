<?php
    ini_set('default_charset', 'UTF-8');
	if(isset($_POST['send'])){
		$nome=$_POST['firstname'];
		$username=$_POST['username'];
		$senha=$_POST['psw'];
		$confirm=$_POST['spsw'];
		$sobrenome=$_POST['lastname'];
		$email=$_POST['email'];
		$confirmEmail=$_POST['cEmail'];
		$data=$_POST['birthday'];
		//    1º. Definir os parâmetros de teste

        $erro = "<br/>";
		
        //  Agora podemos copiar o arquivo enviado
        $destino = 'C:\\xampp\\htdocs\\site\\image\\' .$arquivo['name'];
		if(empty($nome)){
			$erro .= 'Campo "Nome" vazio<br/>';
		}
		else if(empty($sobrenome)){
			$erro .= 'Campo "Sobrenome" vazio<br/>';
		}
		else if(empty($username)){
			$erro .= 'Campo "Usuário" vazio<br/>';
		}
		else if(empty($data)){
			$erro .= 'Campo "Nascimento" vazio<br/>';
        }
		else if(empty($senha)){
			$erro .= 'Campo "Senha" vazio<br/>';
		}
		else if(empty($email)){
			$erro .= 'Campo "e-Mail" vazio<br/>';
		}
		else if($senha != $confirm){
			$erro .= 'As senhas diferem<br/>';
		}
		else if($email != $confirmEmail){
			$erro .= 'Os e-Mails diferem<br/>';
		}
		else if(!filter_var($email, FILTER_VALIDATE_EMAIL)){
			$erro .= 'Formato de e-Mail não aceito<br/>';
		}
		if(isset($erro)):
			echo $erro.'<br />';
           //   header('Location: http://www.google.com/');
		endif;
	}
    
	
?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>cadastro</title>
        <link rel="stylesheet" type="text/css" href="css/style2.css"/>
    </head>
    <body>
        <header>            
            <figure>
                <a href="index.php">
                    <img alt="logo" src="img/logo.png"/>
                </a>
            </figure>
        </header>
        <main>
		
            <h2>The zuera never ends, graças a Deus&trade;!</h2>
            <section>
                <h3>Cadastre-se:</h3>
                <!--<form method="post" enctype="multipart/form-data" action="resposta2.php">-->
                <?php if(!empty($erro)){echo '<p style = "background-color: red; text-align: center; font-size: 20px; font-weight: bold; justify-content: center; padding-bottom: 30px;">'.$erro;}'</p>'?>
				<form method="POST" enctype="multipart/form-data" action="">
                    <p>
                        <label for="firstname" >
                            Nome:
                        </label>
                        <input type="text" name="firstname" id="firstname" value="<?php if(!empty($nome)){echo $nome;} ?>"/>
                    </p>
                    <br>
                    <p>
                        <label for="lastname" >
                            Sobrenome:
                        </label>
                        <input type="text" name="lastname" id ="lastname" value="<?php if(!empty($sobrenome)){echo $sobrenome;} ?>"/>
                    </p>
                    <br>
                    <p>
                        <label for="username" >
                            Usuário:
                        </label>
                        <input type="text" name="username" id ="username" value="<?php if(!empty($username)){echo $username;} ?>"/>
                    </p>
                    <br>
                    <p>
                        <label for="birthday" >
                            Nascimento:
                        </label>
                        <input type="date" name="birthday" id ="birthday" value="<?php if(!empty($data)){echo $data;} ?>"/>
                    </p>
                    <br>
                    <?php if(!empty($erro)){echo '<p style = "background-color: red;
                            text-align: center;
                            font-size: 20px;
                            font-weight: bold;
                            justify-content: center;
                            padding-bottom: 5px;
                            ">Digite novamente o e-Mail e o confirme em seguida</p>';} ?>
                    <p>
                        <label for="email" >
                            e-Mail:
                        </label>
                        <input type="email" name="email" id ="email" value="<?php if(!empty($email)){echo $email;} ?>"/>
                    </p>
                    <br>
                    <p>
                        <label for="cEmail" >
                            Confirme seu e-Mail:
                        </label>
                        <input type="email" name="cEmail" id ="cEmail"/>
                    </p>
                    <br>
                     <?php if(!empty($erro)){echo '<p style = "background-color: red;
                            text-align: center;
                            font-size: 20px;
                            font-weight: bold;
                            justify-content: center;
                            padding-bottom: 5px;
                            ">Digite novamente a senha e a confirme em seguida</p>';} ?>
                    <p>
                        <label for="psw" >
                            Senha:
                        </label>
                        <input type="password" name="psw" id ="psw"/>
                    </p>
                    <br>
                    <p>
                        <label for="spsw" >
                            Confirme a senha:
                        </label>
                        <input type="password" name="spsw" id ="spsw"/>
                    </p>
                    <br>
                    <input type="submit" value="Próximo..." name="send"/>
					
                </form>
            </section>
            </main>
            <footer>
                <nav>
                    <ul>
                        <li>
                            <a href="index.php">
                                Casa
                            </a>
                        </li>
                        <li>
                            <a href="humor.php">
                                Humor
                            </a>
                        </li>
                        <li>
                            <a href="about.php">
                                Sobre
                            </a>
                        </li>
                        <li>
                            <a href="contato.php">
                                Contato
                            </a>
                        </li>
                        <li>
                            <a href="cadastro.php">
                                Cadastro
                            </a>
                        </li>
                    </ul>
                </nav>
                <h4>Copyright &copy;
                    <a target="_blank" href="https://www.facebook.com/araujo.patrick">
                        Patrick Araújo
                    </a> 2018
                </h4>
            </footer>
    </body>
</html>
