CREATE DATABASE TECHFARM;

USE TECHFARM;

CREATE TABLE empresa(
idempresa int primary key auto_increment,
nome varchar(40),
responsavel varchar(40),
email varchar (60),
cnpj char(14) unique,
tipo varchar(7), constraint chktipo check(tipo in ("Matriz", "Filial" )));

CREATE TABLE usuario(
idfuncionario int auto_increment,
email varchar(60),
nome varchar(40),
cpf char(11),
senha varchar(40),
fkempresa int,
constraint cfkempresa foreign key (fkempresa) references empresa(idempresa)
);

CREATE TABLE Silo(
idSilos int primary key auto_increment,
numeraçao int,
capacidadeMax double,
capacidadeMin double,
fkempresa int, constraint chkempresa foreign key (fkempresa) references empresa(idempresa)
);

CREATE TABLE sensor(
idsensor int primary key auto_increment,
sensor varchar(20) default 'DHT11',
numerodeserie char(15),
statussensor varchar(10), 
constraint chkstatus check(statussensor in ("ativo","inativo")),
fksilo int, 
constraint chksilo foreign key (fksilo) references Silo(idSilos)
);

CREATE TABLE logCaptura(
idLog int,
temperatura decimal,
umidade decimal,
data_hora datetime default current_timestamp,
fkSensor int, constraint chklog foreign key (fkSensor) references sensor (idsensor),
Primary key (fksensor, idLog)
);