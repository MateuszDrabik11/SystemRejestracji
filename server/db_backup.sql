--
-- File generated with SQLiteStudio v3.4.4 on pon. cze 3 20:48:09 2024
--
-- Text encoding used: UTF-8
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: account
DROP TABLE IF EXISTS account;
CREATE TABLE IF NOT EXISTS account (username varchar (20) PRIMARY KEY ON CONFLICT IGNORE UNIQUE ON CONFLICT IGNORE, password varchar (20), name varchar (20), familyname varchar (20), type varchar (15));
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwia.dworaczyk55', 'zJSG0iDj', 'Sylwia', 'Dworaczyk', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('nina.białkowska52', 'c5jmuSEe', 'Nina', 'Białkowska', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leopold.pułaski57', 'gU62hEA9', 'Leopold', 'Pułaski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('szarlota.kuberski65', 'PsGSaXj4', 'Szarlota', 'Kuberski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('paweł.mroczek49', 'QVPDKNpz', 'Paweł', 'Mroczek', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('wiara.wojtkiewicz96', 'zdaLrzUt', 'Wiara', 'Wojtkiewicz', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('zenobiusz.głowa78', 'PtISKmd5', 'Zenobiusz', 'Głowa', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('walerian.kostecka70', 'K0FkNASd', 'Walerian', 'Kostecka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('elwira.konopa20', 'nYKJ71FQ', 'Elwira', 'Konopa', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('jolanta.pacyna36', '5Ttjv4ce', 'Jolanta', 'Pacyna', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('janina.antkowiak31', 'xoNQquQj', 'Janina', 'Antkowiak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('janina.konopa53', 'rGfGRO9g', 'Janina', 'Konopa', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('wiara.wojtkiewicz94', 'dQFuNN9N', 'Wiara', 'Wojtkiewicz', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('szarlota.głowa72', 'eUIkWuH8', 'Szarlota', 'Głowa', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('elwira.węgrzyn26', 'BA7xn0j0', 'Elwira', 'Węgrzyn', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('janina.baca99', 'z7xlNrsS', 'Janina', 'Baca', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('eleonora.dworaczyk55', 'KDIkTDcC', 'Eleonora', 'Dworaczyk', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('zenobiusz.jerzak62', 'nQLFDX9t', 'Zenobiusz', 'Jerzak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('borys.pacyna38', 'waOUJ3bL', 'Borys', 'Pacyna', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('wiara.antkowiak76', 'y1pGuvGh', 'Wiara', 'Antkowiak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('jolanta.jerzak66', '95iNLRNR', 'Jolanta', 'Jerzak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('melania.antkowiak89', 'Fi0eKBWW', 'Melania', 'Antkowiak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('oktawiusz.podgórny24', 'ztB9c5UI', 'Oktawiusz', 'Podgórny', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('janina.juras67', 'gDwutKSo', 'Janina', 'Juras', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('paweł.mroczka90', 'bUNkgYgN', 'Paweł', 'Mroczka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.podgórny61', 'dqbbFipZ', 'Daniel', 'Podgórny', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('wiara.baca13', 'YqexfkbA', 'Wiara', 'Baca', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwia.baca97', 'jeZIDNbS', 'Sylwia', 'Baca', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('julita.juras43', 'PTD6Q6sG', 'Julita', 'Juras', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('herbert.sawa52', 'ZY3hZE9S', 'Herbert', 'Sawa', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('zenobiusz.mroczek60', 'kdH4deJ4', 'Zenobiusz', 'Mroczek', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('august.podgórny99', 'uA58RS7h', 'August', 'Podgórny', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('nina.szalkowski24', 'MwXgCyMn', 'Nina', 'Szalkowski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwia.przybyliński33', 'QdsJ1d2P', 'Sylwia', 'Przybyliński', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('barbara.antkowiak76', 'U1KfVgG2', 'Barbara', 'Antkowiak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('paweł.podgórny85', 'N69rx1IC', 'Paweł', 'Podgórny', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('ziemowit.mroczek47', 'J4MJiuuj', 'Ziemowit', 'Mroczek', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.mroczka72', 'eVbvmFIu', 'Daniel', 'Mroczka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('herbert.pacyna68', 'ije5lg7c', 'Herbert', 'Pacyna', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('barbara.juras41', 'c5yEIiHW', 'Barbara', 'Juras', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('oktawiusz.głowa67', '1iU4mpYR', 'Oktawiusz', 'Głowa', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwia.pacyna74', 'mP2BAiEW', 'Sylwia', 'Pacyna', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('borys.mroczek22', 'dpogA1bv', 'Borys', 'Mroczek', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('herbert.rogacka91', 'Byu7CsJJ', 'Herbert', 'Rogacka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('walerian.owsiany98', 'yaK48fUH', 'Walerian', 'Owsiany', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('oktawiusz.pacyna29', 'kf24GOEM', 'Oktawiusz', 'Pacyna', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('jolanta.mazur17', '2SFct8O8', 'Jolanta', 'Mazur', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('kazimiera.kostecka66', 'MGCVDGEH', 'Kazimiera', 'Kostecka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('andrzej.kempka90', 'hZlUd4ej', 'Andrzej', 'Kempka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('herbert.węgrzyn42', 'L640RGKU', 'Herbert', 'Węgrzyn', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('ziemowit.rogacka82', 'gcQDNFkT', 'Ziemowit', 'Rogacka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leon.rogacka90', 'g92Xq5bT', 'Leon', 'Rogacka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leon.kempka17', 'jqvuHu92', 'Leon', 'Kempka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('melania.sawa91', 'VMSughQA', 'Melania', 'Sawa', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('august.pułaski48', 'RpqJEbsC', 'August', 'Pułaski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('nina.mroczka16', 'O8lFILVw', 'Nina', 'Mroczka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.mroczka50', 'oh6Vd4sd', 'Daniel', 'Mroczka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leopold.białkowska98', 'LHBF4Sdd', 'Leopold', 'Białkowska', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('szarlota.dworaczyk96', '11ewQHdF', 'Szarlota', 'Dworaczyk', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('ziemowit.dobosiewicz17', 'tASrJO97', 'Ziemowit', 'Dobosiewicz', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('borys.szalkowski49', 'JyYel3z5', 'Borys', 'Szalkowski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('szarlota.szablewski58', 'X06GuHEc', 'Szarlota', 'Szablewski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('elwira.pacyna79', 'cnu0B6yp', 'Elwira', 'Pacyna', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.mazur60', '7xcGGvMv', 'Daniel', 'Mazur', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.mazur77', 'fWb9SBxH', 'Daniel', 'Mazur', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('kunegunda.owsiany68', 'Fz6AzFaN', 'Kunegunda', 'Owsiany', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('elwira.jerzak22', 'R4MFjRPh', 'Elwira', 'Jerzak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('walerian.mroczek61', 'NGkmDpsN', 'Walerian', 'Mroczek', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwia.juras60', 'A1sgwYNH', 'Sylwia', 'Juras', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('janina.jerzak60', 'vtg3Qxcj', 'Janina', 'Jerzak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('herbert.kuberski94', 'MUkTAQqC', 'Herbert', 'Kuberski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('szarlota.pacyna89', 'tVu8x2qV', 'Szarlota', 'Pacyna', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('barbara.juras22', 'fQOlvxvA', 'Barbara', 'Juras', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('zenobiusz.kempka66', 'Ih16vTf3', 'Zenobiusz', 'Kempka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('ludomir.jerzak32', 'rQxSb94p', 'Ludomir', 'Jerzak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('nina.owsiany99', 'DNV3p6m7', 'Nina', 'Owsiany', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('jolanta.dobosiewicz14', '5St0jgQM', 'Jolanta', 'Dobosiewicz', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('kazimiera.podgórny15', 'bLELVQ4K', 'Kazimiera', 'Podgórny', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('katarzyna.rogacka41', 'maFzyqXG', 'Katarzyna', 'Rogacka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('walerian.juras14', 'bFudx2AK', 'Walerian', 'Juras', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leopold.dobosiewicz88', 'FwfffBvL', 'Leopold', 'Dobosiewicz', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('herbert.baca20', 'FstIUQdh', 'Herbert', 'Baca', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leopold.juras43', 'jiPq8wNQ', 'Leopold', 'Juras', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('nina.mroczka77', 'TjWFaSKZ', 'Nina', 'Mroczka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leon.konopa33', 'R0igw5xI', 'Leon', 'Konopa', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('katarzyna.dobosiewicz77', 'z7dpJ85b', 'Katarzyna', 'Dobosiewicz', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('barbara.antkowiak94', 'uPte9A2t', 'Barbara', 'Antkowiak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('borys.szablewski51', 'nESlKVPa', 'Borys', 'Szablewski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('ludomir.mroczek18', 'Hl4QDnld', 'Ludomir', 'Mroczek', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwester.kuberski59', 'eRAuttxp', 'Sylwester', 'Kuberski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.przybyliński40', 'YRmM4eYb', 'Daniel', 'Przybyliński', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('august.owsiany13', 'BsYqEJta', 'August', 'Owsiany', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('eleonora.głowa46', 'sSFtLueM', 'Eleonora', 'Głowa', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leopold.podgórny97', 'loi38St3', 'Leopold', 'Podgórny', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('borys.węgrzyn56', 'A070FgYW', 'Borys', 'Węgrzyn', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leon.szablewski73', 'OL9KvYIQ', 'Leon', 'Szablewski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('barbara.węgrzyn29', 'sZSlmoRX', 'Barbara', 'Węgrzyn', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('nina.szalkowski65', 'sRTWOSKP', 'Nina', 'Szalkowski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.ligas82', 'u5DZhQ6M', 'Daniel', 'Ligas', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('beata.mroczka52', 'ZRrCFx3q', 'Beata', 'Mroczka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('nina.pułaski57', 'CXQJYIol', 'Nina', 'Pułaski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('nina.pacyna47', 'SHg3Xk5E', 'Nina', 'Pacyna', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('jolanta.bien17', 'pYbhb1O6', 'Jolanta', 'Bien', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('herbert.antkowiak50', 'NuPlB5t6', 'Herbert', 'Antkowiak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.węgrzyn44', 'Ib0pCFh8', 'Daniel', 'Węgrzyn', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('zenobiusz.mazur62', 'nJsCtSeg', 'Zenobiusz', 'Mazur', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('august.sawa13', '0hIIgmHf', 'August', 'Sawa', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('oktawiusz.białkowska34', 'BGL7S08w', 'Oktawiusz', 'Białkowska', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwester.dobosiewicz77', 'NjVkXbGX', 'Sylwester', 'Dobosiewicz', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('herbert.juras24', '0OtbYUhE', 'Herbert', 'Juras', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwia.kostecka92', 'X3E5JUIC', 'Sylwia', 'Kostecka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('august.kostecka82', '3SpNoAZp', 'August', 'Kostecka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('melania.antkowiak91', 'RYX0J20q', 'Melania', 'Antkowiak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('andrzej.kostecka10', '5EBRnB4O', 'Andrzej', 'Kostecka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.konopa98', 'SpAp7B0r', 'Daniel', 'Konopa', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('elwira.kostecka46', 'm0r0926f', 'Elwira', 'Kostecka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('romuald.wojtkiewicz85', 'Xgw52EA3', 'Romuald', 'Wojtkiewicz', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('katarzyna.głowa77', 'bxPvkevF', 'Katarzyna', 'Głowa', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('ludomir.szalkowski44', 'Nf3oRFjP', 'Ludomir', 'Szalkowski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('kunegunda.rogacka51', 'eOUgJOpc', 'Kunegunda', 'Rogacka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('paweł.antkowiak58', 'ScX4hbl4', 'Paweł', 'Antkowiak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leopold.mroczek18', 'NOg16ZDu', 'Leopold', 'Mroczek', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwia.kostuch79', '7G6F4wl0', 'Sylwia', 'Kostuch', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('barbara.kostuch30', 'GeUCfMXB', 'Barbara', 'Kostuch', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('kazimiera.jerzak50', 'nIOYuRN7', 'Kazimiera', 'Jerzak', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('barbara.głowa27', 'NuI1ZrUC', 'Barbara', 'Głowa', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('julita.białkowska15', '4NdLBWXK', 'Julita', 'Białkowska', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwia.szablewski78', 'j5Abv1tu', 'Sylwia', 'Szablewski', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leon.rogacka39', 'NHnBCnLu', 'Leon', 'Rogacka', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('ziemowit.pacyna69', 'yBVeT7sm', 'Ziemowit', 'Pacyna', 'patient');
INSERT INTO account (username, password, name, familyname, type) VALUES ('borys.węgrzyn16', 'H1D9ZZnq', 'Borys', 'Węgrzyn', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('wiara.pacyna66', 'VxPUXSTk', 'Wiara', 'Pacyna', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('julita.młodzik36', 'PHlDFA7d', 'Julita', 'Młodzik', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('borys.mroczek11', 'VWkDzQAd', 'Borys', 'Mroczek', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('oktawiusz.przybyliński66', 'dUIUjLb5', 'Oktawiusz', 'Przybyliński', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('romuald.juras74', 'mhcSGxdh', 'Romuald', 'Juras', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('wiara.węgrzyn46', 'obU3RyNx', 'Wiara', 'Węgrzyn', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('katarzyna.kostecka51', 'r7N6kC1u', 'Katarzyna', 'Kostecka', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leopold.sawa73', 'UF3bFh9B', 'Leopold', 'Sawa', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('zenobiusz.szalkowski61', 'g9cE1rm4', 'Zenobiusz', 'Szalkowski', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwia.głowa89', 'eC364YoJ', 'Sylwia', 'Głowa', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('nina.mazur68', '7n8D9HTy', 'Nina', 'Mazur', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('kazimiera.kostecka23', 'u5SreE5R', 'Kazimiera', 'Kostecka', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('katarzyna.juras66', '4QvLPi1T', 'Katarzyna', 'Juras', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('barbara.dobosiewicz28', 'ms8kLX7i', 'Barbara', 'Dobosiewicz', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('walerian.kostuch28', 'mzcRlm0l', 'Walerian', 'Kostuch', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('eleonora.szablewski45', 'VSGT8dkl', 'Eleonora', 'Szablewski', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('eleonora.mroczka50', '2Zs5EG7Q', 'Eleonora', 'Mroczka', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('szarlota.mroczek77', 'C59wrVF3', 'Szarlota', 'Mroczek', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('beata.mroczka61', '4Mu2UoAn', 'Beata', 'Mroczka', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('august.podgórny41', 'iO97iU2I', 'August', 'Podgórny', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('jolanta.juras32', '39F1ew0u', 'Jolanta', 'Juras', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('borys.mazur71', 'EQcEgJxg', 'Borys', 'Mazur', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('andrzej.kuberski45', 'EsHSb1PO', 'Andrzej', 'Kuberski', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('andrzej.pacyna29', 'iHHDmz9S', 'Andrzej', 'Pacyna', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leon.bien94', 'a3yUopz1', 'Leon', 'Bien', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwester.owsiany31', '3oizaWuU', 'Sylwester', 'Owsiany', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('kazimiera.szablewski20', 'ru6bKX9E', 'Kazimiera', 'Szablewski', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('beata.owsiany19', '58tcto0F', 'Beata', 'Owsiany', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('nina.młodzik85', 'Xg4pKcVi', 'Nina', 'Młodzik', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('oktawiusz.kempka10', '79ElHnTP', 'Oktawiusz', 'Kempka', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('julita.głowa29', 'Ty0D0MGU', 'Julita', 'Głowa', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.konopa54', 'FVyrUwH4', 'Daniel', 'Konopa', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('janina.bien43', 'KFywXFyW', 'Janina', 'Bien', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('barbara.wojtkiewicz93', 'XyP3nNsK', 'Barbara', 'Wojtkiewicz', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('elwira.juras46', 'tDPnNzoa', 'Elwira', 'Juras', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('ludomir.pułaski64', 'tb3I5jtq', 'Ludomir', 'Pułaski', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.dobosiewicz73', 'dHoiz1qg', 'Daniel', 'Dobosiewicz', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('melania.mroczek98', 'hkQrLGaM', 'Melania', 'Mroczek', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('andrzej.rogacka20', 'q6joP8uP', 'Andrzej', 'Rogacka', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('barbara.konopa24', 'XclqcTaE', 'Barbara', 'Konopa', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.sawa65', 'CpVXIp27', 'Daniel', 'Sawa', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('kazimiera.szablewski23', 'V2fyOkmx', 'Kazimiera', 'Szablewski', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('zenobiusz.jerzak36', '20Pc5kmb', 'Zenobiusz', 'Jerzak', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('elwira.szalkowski79', 'rmMyKVxr', 'Elwira', 'Szalkowski', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('julita.młodzik48', 'zu2e8iuE', 'Julita', 'Młodzik', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('andrzej.ligas81', '1yNQqy52', 'Andrzej', 'Ligas', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwester.sawa39', 'lg0g8xen', 'Sylwester', 'Sawa', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.pułaski46', 'q4QB9Ah4', 'Daniel', 'Pułaski', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('nina.kempka94', 'yQ9ERoC4', 'Nina', 'Kempka', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('kazimiera.dobosiewicz23', 'YH6clpbl', 'Kazimiera', 'Dobosiewicz', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('barbara.przybyliński71', 'nox9LRSd', 'Barbara', 'Przybyliński', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('paweł.kempka39', 'hKrPu4XZ', 'Paweł', 'Kempka', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('eleonora.dobosiewicz38', 'EmoJFZqw', 'Eleonora', 'Dobosiewicz', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('elwira.jerzak95', 'XFNx8JIp', 'Elwira', 'Jerzak', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('melania.mroczek48', 'PvSrewjS', 'Melania', 'Mroczek', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('melania.baca80', 'WFhVPDZG', 'Melania', 'Baca', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('romuald.ligas54', '6phsHaSa', 'Romuald', 'Ligas', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('barbara.głowa66', 'yQJQ0NkZ', 'Barbara', 'Głowa', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('zenobiusz.mroczka90', 'maNaj55T', 'Zenobiusz', 'Mroczka', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('katarzyna.kostuch59', 'LWRhDTnZ', 'Katarzyna', 'Kostuch', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('daniel.owsiany91', 'c7SbZxuW', 'Daniel', 'Owsiany', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('julita.kempka68', 'ycdaCD7w', 'Julita', 'Kempka', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('janina.młodzik79', 'K5Atipq5', 'Janina', 'Młodzik', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwester.wojtkiewicz36', 'Q6MUlkYi', 'Sylwester', 'Wojtkiewicz', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('herbert.mroczek24', 'qu3oKWxj', 'Herbert', 'Mroczek', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leopold.juras96', 'DI8ns9Vp', 'Leopold', 'Juras', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('august.przybyliński54', 'eQoX0yiC', 'August', 'Przybyliński', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('romuald.węgrzyn32', '5P8BNNIl', 'Romuald', 'Węgrzyn', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('wiara.szablewski13', 'OTQSwsG5', 'Wiara', 'Szablewski', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('august.ligas54', 'WzQWdQtL', 'August', 'Ligas', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwester.podgórny43', 'eZtAsGXd', 'Sylwester', 'Podgórny', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('jolanta.białkowska60', 'lGrbmM1p', 'Jolanta', 'Białkowska', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('romuald.bien38', 'G3hSJkzA', 'Romuald', 'Bien', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('paweł.szalkowski86', 'HLE14wdx', 'Paweł', 'Szalkowski', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('eleonora.szalkowski85', 'B1eVcLoZ', 'Eleonora', 'Szalkowski', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('borys.rogacka82', 'okxUopvS', 'Borys', 'Rogacka', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('janina.kuberski82', 'Z3SUCsVx', 'Janina', 'Kuberski', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leon.antkowiak37', '9usRmGg3', 'Leon', 'Antkowiak', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('ziemowit.kempka89', 'XY16Shpm', 'Ziemowit', 'Kempka', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('jolanta.ligas42', 'zAcpIwOT', 'Jolanta', 'Ligas', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('janina.baca86', 'LEfRg2vR', 'Janina', 'Baca', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leopold.kempka11', 'GLFUCP9m', 'Leopold', 'Kempka', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('ludomir.mroczek49', 'mwi3fA6G', 'Ludomir', 'Mroczek', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('janina.węgrzyn53', 'dQKqaGRU', 'Janina', 'Węgrzyn', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('katarzyna.wojtkiewicz42', 'TrgmuxM7', 'Katarzyna', 'Wojtkiewicz', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('walerian.głowa61', 'o4C7BMb9', 'Walerian', 'Głowa', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('janina.pacyna32', 'IyflWcvT', 'Janina', 'Pacyna', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('szarlota.konopa99', 'kB72dP3b', 'Szarlota', 'Konopa', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('paweł.sawa67', 'ltMGYX0w', 'Paweł', 'Sawa', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('barbara.rogacka76', 't2gKiFvF', 'Barbara', 'Rogacka', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('paweł.kempka26', 'm28CG38G', 'Paweł', 'Kempka', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('sylwia.kostecka78', 'ccYX1XDi', 'Sylwia', 'Kostecka', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('wiara.białkowska45', 'ys5S4z0k', 'Wiara', 'Białkowska', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('ludomir.rogacka10', 'MWUdcOoT', 'Ludomir', 'Rogacka', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('ziemowit.pacyna77', 'XV9VNqXZ', 'Ziemowit', 'Pacyna', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('leopold.owsiany96', 'v2gkGE34', 'Leopold', 'Owsiany', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('elwira.białkowska54', 'jsiQqWl4', 'Elwira', 'Białkowska', 'doctor');
INSERT INTO account (username, password, name, familyname, type) VALUES ('beata.mroczek72', 'O4CIKLLY', 'Beata', 'Mroczek', 'registration');
INSERT INTO account (username, password, name, familyname, type) VALUES ('prywatnie', 'AAAAAAAAAAAAAAAAAAA', 'prywatnie', '', 'prywatnie');
INSERT INTO account (username, password, name, familyname, type) VALUES ('null', 'AAAAAAAAAAAAAAAAAAA', 'null', 'null', 'null');

-- Table: ekg_res
DROP TABLE IF EXISTS ekg_res;
CREATE TABLE IF NOT EXISTS ekg_res (res_id INTEGER REFERENCES exam (results) ON DELETE CASCADE UNIQUE, rhytm INTEGER, pr_delay INTEGER, qrs INTEGER);
INSERT INTO ekg_res (res_id, rhytm, pr_delay, qrs) VALUES (18, 57, 100, 80);
INSERT INTO ekg_res (res_id, rhytm, pr_delay, qrs) VALUES (35, 66, 131, 256);
INSERT INTO ekg_res (res_id, rhytm, pr_delay, qrs) VALUES (36, 66, 66, 234);
INSERT INTO ekg_res (res_id, rhytm, pr_delay, qrs) VALUES (37, 113, 2, 115);
INSERT INTO ekg_res (res_id, rhytm, pr_delay, qrs) VALUES (39, 154, 118, 81);
INSERT INTO ekg_res (res_id, rhytm, pr_delay, qrs) VALUES (56, 90, 80, 136);
INSERT INTO ekg_res (res_id, rhytm, pr_delay, qrs) VALUES (58, 63, 57, 218);
INSERT INTO ekg_res (res_id, rhytm, pr_delay, qrs) VALUES (61, 150, 36, 236);
INSERT INTO ekg_res (res_id, rhytm, pr_delay, qrs) VALUES (64, 118, 42, 198);
INSERT INTO ekg_res (res_id, rhytm, pr_delay, qrs) VALUES (71, 41, 57, 70);
INSERT INTO ekg_res (res_id, rhytm, pr_delay, qrs) VALUES (74, 64, 77, 300);

-- Table: exam
DROP TABLE IF EXISTS exam;
CREATE TABLE IF NOT EXISTS exam (exam_id INTEGER REFERENCES med_event (med_event_id) ON DELETE CASCADE, who_performs REFERENCES account (username) ON DELETE CASCADE, "when" datetime, results INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, room varchar (40));
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (10, 'eleonora.szablewski45', '2022-04-26 11:00:00', 10, '168');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (14, 'eleonora.mroczka50', '2026-01-09 16:00:00', 11, '292');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (15, 'wiara.szablewski13', '2022-06-08 17:00:00', 12, '144');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (16, 'katarzyna.kostuch59', '2023-09-29 06:00:00', 13, '152');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (17, 'sylwia.głowa89', '2024-07-27 14:00:00', 14, '101');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (20, 'eleonora.mroczka50', '2024-04-13 14:00:00', 15, '142');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (21, 'barbara.głowa66', '2026-03-23 13:00:00', 16, '46');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (23, 'daniel.dobosiewicz73', '2026-03-17 16:00:00', 17, '37');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (24, 'andrzej.rogacka20', '2023-11-16 11:00:00', 18, '4');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (30, 'elwira.szalkowski79', '2022-11-17 12:00:00', 19, '185');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (32, 'daniel.sawa65', '2023-05-22 12:00:00', 20, '89');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (33, 'szarlota.mroczek77', '2022-08-10 14:00:00', 21, '50');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (34, 'katarzyna.kostecka51', '2023-10-31 12:00:00', 22, '238');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (36, 'zenobiusz.szalkowski61', '2026-06-03 13:00:00', 23, '4');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (37, 'august.przybyliński54', '2022-04-26 13:00:00', 24, '266');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (39, 'ziemowit.pacyna77', '2023-02-15 14:00:00', 25, '232');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (41, 'daniel.sawa65', '2024-08-02 10:00:00', 26, '83');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (42, 'daniel.sawa65', '2024-09-18 13:00:00', 27, '285');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (43, 'andrzej.ligas81', '2024-03-08 14:00:00', 28, '221');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (44, 'romuald.bien38', '2025-12-29 08:00:00', 29, '299');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (45, 'eleonora.szablewski45', '2025-04-24 08:00:00', 30, '207');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (46, 'walerian.głowa61', '2023-02-10 17:00:00', 31, '282');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (47, 'wiara.pacyna66', '2026-02-23 15:00:00', 32, '34');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (50, 'august.podgórny41', '2023-07-09 06:00:00', 33, '78');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (51, 'daniel.owsiany91', '2026-04-12 16:00:00', 34, '112');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (52, 'kazimiera.dobosiewicz23', '2026-05-24 13:00:00', 35, '51');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (53, 'paweł.sawa67', '2026-04-13 12:00:00', 36, '299');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (54, 'szarlota.mroczek77', '2026-12-26 16:00:00', 37, '173');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (55, 'jolanta.ligas42', '2021-12-15 16:00:00', 38, '23');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (56, 'elwira.juras46', '2026-03-03 07:00:00', 39, '202');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (58, 'katarzyna.kostuch59', '2025-04-23 13:00:00', 40, '15');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (59, 'nina.młodzik85', '2026-03-09 11:00:00', 41, '114');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (60, 'julita.głowa29', '2026-02-14 17:00:00', 42, '122');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (63, 'julita.głowa29', '2025-01-18 10:00:00', 43, '4');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (65, 'elwira.szalkowski79', '2025-11-01 11:00:00', 44, '260');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (67, 'ludomir.rogacka10', '2024-07-15 14:00:00', 45, '178');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (68, 'katarzyna.kostuch59', '2026-01-16 14:00:00', 46, '281');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (69, 'sylwester.wojtkiewicz36', '2025-07-13 06:00:00', 47, '138');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (70, 'walerian.głowa61', '2023-07-02 16:00:00', 48, '284');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (71, 'daniel.dobosiewicz73', '2024-04-19 09:00:00', 49, '94');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (73, 'szarlota.mroczek77', '2024-06-01 08:00:00', 50, '40');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (75, 'barbara.konopa24', '2024-08-26 16:00:00', 51, '47');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (76, 'ludomir.rogacka10', '2021-09-25 09:00:00', 52, '165');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (81, 'romuald.węgrzyn32', '2023-05-08 06:00:00', 53, '114');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (82, 'elwira.juras46', '2025-07-01 07:00:00', 54, '241');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (83, 'paweł.sawa67', '2024-01-05 10:00:00', 55, '187');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (84, 'elwira.białkowska54', '2025-01-06 14:00:00', 56, '40');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (85, 'wiara.pacyna66', '2025-07-30 16:00:00', 57, '43');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (86, 'daniel.dobosiewicz73', '2026-02-06 17:00:00', 58, '237');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (87, 'andrzej.ligas81', '2022-12-18 11:00:00', 59, '83');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (88, 'sylwia.głowa89', '2026-11-18 12:00:00', 60, '34');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (89, 'barbara.konopa24', '2025-04-04 11:00:00', 61, '27');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (90, 'daniel.owsiany91', '2025-07-27 13:00:00', 62, '13');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (91, 'andrzej.ligas81', '2025-07-11 12:00:00', 63, '57');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (92, 'sylwester.podgórny43', '2022-04-03 17:00:00', 64, '273');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (95, 'daniel.sawa65', '2023-09-04 16:00:00', 65, '298');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (97, 'zenobiusz.szalkowski61', '2021-11-04 07:00:00', 66, '260');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (98, 'sylwester.podgórny43', '2022-03-17 15:00:00', 67, '248');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (99, 'walerian.głowa61', '2023-04-19 07:00:00', 68, '81');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (101, 'eleonora.mroczka50', '2023-09-10 07:00:00', 69, '250');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (103, 'janina.kuberski82', '2021-11-15 14:00:00', 70, '15');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (105, 'sylwia.głowa89', '2022-04-02 12:00:00', 71, '263');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (107, 'august.podgórny41', '2026-02-18 13:00:00', 72, '32');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (108, 'julita.głowa29', '2023-01-25 17:00:00', 73, '176');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (109, 'kazimiera.kostecka23', '2023-05-30 06:00:00', 74, '296');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (123, 'szarlota.konopa99', '2024-05-14 06:00:00', 76, '120');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (148, 'szarlota.konopa99', '2024-05-15 10:30:00', 95, '100000');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (149, 'szarlota.konopa99', '2024-05-15 08:00:00', 96, '00000');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (150, 'szarlota.konopa99', '2024-05-15 08:20:00', 97, '00001');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (151, 'szarlota.konopa99', '2024-05-15 08:20:00', 98, '00001');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (152, 'szarlota.konopa99', '2024-05-15 08:20:00', 99, '00001');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (153, 'szarlota.konopa99', '2024-05-15 08:20:00', 100, '696969');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (156, 'szarlota.konopa99', '2024-05-15 12:30:00', 101, '000000');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (157, 'szarlota.konopa99', '2024-05-15 09:00:00', 102, '-1212');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (158, 'szarlota.konopa99', '2024-05-15 09:00:00', 103, '-1212');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (159, 'szarlota.konopa99', '2024-05-15 10:00:00', 106, '222');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (162, 'szarlota.konopa99', '2024-05-15 06:00:00', 110, '-1');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (163, 'szarlota.konopa99', '2024-05-15 11:00:00', 112, '-10');
INSERT INTO exam (exam_id, who_performs, "when", results, room) VALUES (165, 'szarlota.konopa99', '2024-05-15 11:30:00', 113, '12');

-- Table: med_event
DROP TABLE IF EXISTS med_event;
CREATE TABLE IF NOT EXISTS med_event (med_event_id INTEGER UNIQUE PRIMARY KEY ON CONFLICT IGNORE AUTOINCREMENT, name varchar (45), describtion TEXT, who_prescribed varchar (20) REFERENCES account (username) ON DELETE CASCADE, room varchar (40), done tinyint, time datetime);
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (10, 'sylwia.przybyliński33', 'mri', 'daniel.owsiany91', '6', 0, '2026-01-30 10:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (11, 'leon.konopa33', 'zabieg', 'daniel.owsiany91', '100', 0, '2022-04-03 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (12, 'sylwester.dobosiewicz77', 'recepta', 'daniel.owsiany91', '17', 0, '2026-06-09 07:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (13, 'oktawiusz.białkowska34', 'wizyta', 'daniel.owsiany91', '296', 0, '2022-01-16 09:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (14, 'katarzyna.głowa77', 'mri', 'daniel.owsiany91', '194', 0, '2022-07-13 09:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (15, 'leopold.białkowska98', 'rtg', 'daniel.owsiany91', '38', 0, '2022-06-21 15:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (16, 'herbert.węgrzyn42', 'morfologia', 'daniel.owsiany91', '113', 0, '2023-06-07 12:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (17, 'zenobiusz.jerzak62', 'morfologia', 'daniel.owsiany91', '61', 0, '2025-06-06 15:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (18, 'paweł.podgórny85', 'wizyta', 'daniel.owsiany91', '155', 0, '2023-02-10 14:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (19, 'eleonora.głowa46', 'wizyta', 'daniel.owsiany91', '153', 0, '2025-03-20 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (20, 'melania.sawa91', 'rtg', 'romuald.juras74', '260', 0, '2025-08-15 12:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (21, 'walerian.juras14', 'rtg', 'romuald.juras74', '266', 0, '2021-12-06 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (22, 'jolanta.pacyna36', 'wizyta', 'romuald.juras74', '245', 0, '2022-09-10 08:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (23, 'kazimiera.kostecka66', 'mri', 'romuald.juras74', '100', 0, '2023-03-16 07:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (24, 'august.podgórny99', 'ekg', 'romuald.juras74', '93', 0, '2024-02-02 17:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (25, 'daniel.podgórny61', 'wizyta', 'romuald.juras74', '122', 0, '2023-07-22 16:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (26, 'barbara.kostuch30', 'recepta', 'romuald.juras74', '55', 0, '2021-12-17 16:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (27, 'sylwia.szablewski78', 'wizyta', 'romuald.juras74', '277', 0, '2024-06-08 14:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (28, 'elwira.węgrzyn26', 'zabieg', 'romuald.juras74', '89', 0, '2022-07-22 17:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (29, 'borys.mroczek22', 'wizyta', 'romuald.juras74', '297', 0, '2021-11-26 14:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (30, 'szarlota.pacyna89', 'morfologia', 'romuald.ligas54', '99', 0, '2026-09-21 16:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (31, 'nina.białkowska52', 'recepta', 'romuald.ligas54', '284', 0, '2025-04-20 09:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (32, 'daniel.podgórny61', 'mri', 'romuald.ligas54', '139', 0, '2026-04-17 06:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (33, 'jolanta.dobosiewicz14', 'rtg', 'romuald.ligas54', '181', 0, '2025-10-26 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (34, 'nina.pacyna47', 'rtg', 'romuald.ligas54', '259', 0, '2021-08-16 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (35, 'leon.konopa33', 'recepta', 'romuald.ligas54', '157', 0, '2025-10-30 09:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (36, 'sylwia.baca97', 'usg', 'romuald.ligas54', '108', 0, '2026-10-19 16:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (37, 'ludomir.szalkowski44', 'usg', 'romuald.ligas54', '56', 0, '2025-10-07 13:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (38, 'leon.kempka17', 'wizyta', 'romuald.ligas54', '72', 0, '2023-04-27 07:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (39, 'wiara.wojtkiewicz94', 'mri', 'romuald.ligas54', '98', 0, '2025-09-09 16:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (40, 'sylwia.przybyliński33', 'zabieg', 'august.przybyliński54', '176', 0, '2026-02-06 15:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (41, 'nina.owsiany99', 'morfologia', 'august.przybyliński54', '144', 0, '2022-04-15 09:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (42, 'oktawiusz.białkowska34', 'rtg', 'august.przybyliński54', '18', 0, '2026-05-20 15:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (43, 'ludomir.mroczek18', 'rtg', 'august.przybyliński54', '227', 0, '2025-03-03 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (44, 'borys.szablewski51', 'rtg', 'august.przybyliński54', '44', 0, '2024-10-19 16:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (45, 'daniel.mroczka72', 'morfologia', 'august.przybyliński54', '75', 0, '2024-04-09 06:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (46, 'szarlota.szablewski58', 'usg', 'august.przybyliński54', '245', 0, '2021-11-04 07:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (47, 'august.podgórny99', 'usg', 'august.przybyliński54', '216', 0, '2022-05-12 14:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (48, 'ludomir.szalkowski44', 'recepta', 'august.przybyliński54', '210', 0, '2024-06-11 08:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (49, 'romuald.wojtkiewicz85', 'zabieg', 'august.przybyliński54', '176', 0, '2025-05-27 08:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (50, 'walerian.juras14', 'morfologia', 'eleonora.mroczka50', '180', 0, '2022-06-21 17:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (51, 'katarzyna.rogacka41', 'rtg', 'eleonora.mroczka50', '194', 0, '2022-04-08 06:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (52, 'leon.rogacka90', 'ekg', 'eleonora.mroczka50', '265', 0, '2021-11-19 13:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (53, 'barbara.węgrzyn29', 'ekg', 'eleonora.mroczka50', '15', 0, '2024-08-30 17:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (54, 'wiara.antkowiak76', 'ekg', 'eleonora.mroczka50', '282', 0, '2022-12-24 08:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (55, 'august.pułaski48', 'rtg', 'eleonora.mroczka50', '2', 0, '2025-08-23 16:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (56, 'zenobiusz.jerzak62', 'ekg', 'eleonora.mroczka50', '65', 0, '2025-05-15 12:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (57, 'daniel.mroczka50', 'wizyta', 'eleonora.mroczka50', '290', 0, '2024-05-11 15:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (58, 'walerian.mroczek61', 'mri', 'eleonora.mroczka50', '284', 0, '2025-01-19 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (59, 'barbara.juras22', 'morfologia', 'eleonora.mroczka50', '150', 0, '2024-08-10 14:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (60, 'eleonora.dworaczyk55', 'rtg', 'wiara.węgrzyn46', '182', 0, '2022-12-09 12:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (61, 'nina.białkowska52', 'recepta', 'wiara.węgrzyn46', '74', 0, '2023-04-21 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (62, 'andrzej.kempka90', 'zabieg', 'wiara.węgrzyn46', '63', 0, '2025-02-19 06:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (63, 'zenobiusz.mroczek60', 'rtg', 'wiara.węgrzyn46', '94', 0, '2022-12-09 09:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (64, 'nina.pułaski57', 'zabieg', 'wiara.węgrzyn46', '229', 0, '2022-08-22 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (65, 'oktawiusz.pacyna29', 'rtg', 'wiara.węgrzyn46', '106', 0, '2022-10-05 08:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (66, 'andrzej.kostecka10', 'wizyta', 'wiara.węgrzyn46', '88', 0, '2025-05-13 17:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (67, 'janina.jerzak60', 'usg', 'wiara.węgrzyn46', '83', 0, '2025-07-21 09:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (68, 'barbara.węgrzyn29', 'mri', 'wiara.węgrzyn46', '75', 0, '2026-08-27 16:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (69, 'borys.pacyna38', 'usg', 'wiara.węgrzyn46', '36', 0, '2026-10-29 16:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (70, 'barbara.antkowiak94', 'rtg', 'borys.mazur71', '110', 0, '2026-06-11 14:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (71, 'janina.jerzak60', 'mri', 'borys.mazur71', '147', 0, '2026-12-24 17:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (72, 'daniel.przybyliński40', 'zabieg', 'borys.mazur71', '57', 0, '2026-12-15 13:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (73, 'walerian.kostecka70', 'usg', 'borys.mazur71', '46', 0, '2021-10-17 07:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (74, 'sylwia.dworaczyk55', 'zabieg', 'borys.mazur71', '207', 1, '2025-10-25 15:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (75, 'melania.antkowiak89', 'rtg', 'borys.mazur71', '219', 0, '2023-07-04 17:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (76, 'sylwia.baca97', 'usg', 'borys.mazur71', '82', 0, '2025-01-20 09:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (77, 'leopold.podgórny97', 'recepta', 'borys.mazur71', '103', 0, '2027-01-27 16:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (78, 'katarzyna.głowa77', 'wizyta', 'borys.mazur71', '165', 0, '2024-03-19 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (79, 'oktawiusz.podgórny24', 'wizyta', 'borys.mazur71', '204', 0, '2021-09-01 08:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (80, 'sylwia.baca97', 'wizyta', 'katarzyna.kostuch59', '73', 0, '2026-04-09 17:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (81, 'sylwia.kostuch79', 'rtg', 'katarzyna.kostuch59', '262', 0, '2026-09-02 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (82, 'paweł.antkowiak58', 'rtg', 'katarzyna.kostuch59', '194', 0, '2022-08-26 08:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (83, 'sylwia.szablewski78', 'rtg', 'katarzyna.kostuch59', '8', 0, '2024-06-14 10:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (84, 'wiara.wojtkiewicz96', 'ekg', 'katarzyna.kostuch59', '45', 0, '2026-03-19 14:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (85, 'ludomir.jerzak32', 'rtg', 'katarzyna.kostuch59', '116', 0, '2025-04-27 06:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (86, 'zenobiusz.mazur62', 'ekg', 'katarzyna.kostuch59', '178', 0, '2022-12-04 10:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (87, 'sylwia.pacyna74', 'morfologia', 'katarzyna.kostuch59', '59', 0, '2022-11-09 16:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (88, 'ziemowit.mroczek47', 'morfologia', 'katarzyna.kostuch59', '12', 0, '2025-09-07 14:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (89, 'nina.szalkowski24', 'ekg', 'katarzyna.kostuch59', '258', 0, '2026-02-27 13:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (90, 'ludomir.mroczek18', 'usg', 'walerian.głowa61', '106', 0, '2023-10-10 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (91, 'eleonora.głowa46', 'mri', 'walerian.głowa61', '115', 0, '2022-01-31 14:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (92, 'janina.antkowiak31', 'ekg', 'walerian.głowa61', '271', 0, '2022-01-03 17:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (93, 'sylwia.baca97', 'zabieg', 'walerian.głowa61', '51', 0, '2022-02-24 12:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (94, 'wiara.baca13', 'zabieg', 'walerian.głowa61', '265', 0, '2024-01-22 07:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (95, 'daniel.mroczka50', 'rtg', 'walerian.głowa61', '196', 0, '2025-10-21 10:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (96, 'beata.mroczka52', 'zabieg', 'walerian.głowa61', '221', 0, '2023-08-12 14:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (97, 'melania.antkowiak91', 'usg', 'walerian.głowa61', '175', 0, '2024-06-09 07:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (98, 'wiara.wojtkiewicz96', 'mri', 'walerian.głowa61', '240', 0, '2026-09-12 08:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (99, 'zenobiusz.kempka66', 'morfologia', 'walerian.głowa61', '245', 0, '2025-08-30 15:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (100, 'sylwia.kostuch79', 'wizyta', 'kazimiera.szablewski23', '125', 0, '2023-07-13 16:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (101, 'ludomir.szalkowski44', 'mri', 'kazimiera.szablewski23', '103', 0, '2022-07-09 09:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (102, 'julita.białkowska15', 'recepta', 'kazimiera.szablewski23', '241', 0, '2025-01-10 12:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (103, 'eleonora.dworaczyk55', 'usg', 'kazimiera.szablewski23', '1', 0, '2023-10-02 06:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (104, 'walerian.juras14', 'wizyta', 'kazimiera.szablewski23', '50', 0, '2023-03-30 12:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (105, 'paweł.mroczek49', 'ekg', 'kazimiera.szablewski23', '111', 0, '2021-11-22 16:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (106, 'janina.juras67', 'zabieg', 'kazimiera.szablewski23', '17', 0, '2021-09-23 07:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (107, 'elwira.konopa20', 'rtg', 'kazimiera.szablewski23', '256', 0, '2022-07-05 09:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (108, 'barbara.juras22', 'rtg', 'kazimiera.szablewski23', '68', 0, '2022-11-05 15:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (109, 'romuald.wojtkiewicz85', 'ekg', 'kazimiera.szablewski23', '44', 0, '2024-03-28 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (110, 'sylwia.dworaczyk55', 'wizyta', 'daniel.sawa65', '100', 1, '2024-05-14 06:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (111, 'leopold.pułaski57', 'wizyta', 'daniel.sawa65', '100', 0, '2024-05-14 07:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (112, 'wiara.wojtkiewicz96', 'wizyta', 'daniel.sawa65', '100', 0, '2024-05-14 08:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (113, 'janina.antkowiak31', 'wizyta', 'daniel.sawa65', '100', 0, '2024-05-14 09:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (114, 'jolanta.pacyna36', 'wizyta', 'daniel.sawa65', '100', 0, '2024-05-14 10:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (115, 'oktawiusz.podgórny24', 'wizyta', 'daniel.sawa65', '100', 0, '2024-05-14 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (116, 'sylwia.dworaczyk55', 'wizyta', 'szarlota.konopa99', '110', 1, '2024-05-14 06:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (117, 'leopold.pułaski57', 'wizyta', 'szarlota.konopa99', '110', 0, '2024-05-14 07:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (118, 'wiara.wojtkiewicz96', 'wizyta', 'szarlota.konopa99', '110', 0, '2024-05-14 08:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (119, 'janina.antkowiak31', 'wizyta', 'szarlota.konopa99', '110', 0, '2024-05-14 09:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (120, 'jolanta.pacyna36', 'wizyta', 'szarlota.konopa99', '110', 0, '2024-05-14 10:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (121, 'jolanta.pacyna36', 'wizyta', 'szarlota.konopa99', '110', 0, '2024-05-14 14:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (122, 'sylwia.dworaczyk55', 'rtg', 'daniel.sawa65', '210', 1, '2024-05-14 06:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (123, 'leopold.pułaski57', 'rtg', 'daniel.sawa65', '210', 0, '2024-05-14 08:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (124, 'sylwia.dworaczyk55', 'wizyta', 'daniel.sawa65', '12', 1, '2024-05-14 12:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (125, 'sylwia.dworaczyk55', 'wizyta', 'daniel.sawa65', '12', 1, '2024-05-14 12:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (126, 'sylwia.baca97', 'wizyta', 'daniel.sawa65', '12', 0, '2024-05-14 13:30:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (127, 'sylwia.baca97', 'wizyta', 'daniel.sawa65', '12', 0, '2024-05-14 13:30:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (128, 'sylwia.dworaczyk55', 'wizyta', 'szarlota.konopa99', '12', 1, '2024-05-14 10:26:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (129, 'sylwia.dworaczyk55', 'wizyta', 'szarlota.konopa99', '12', 1, '2024-05-14 09:30:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (131, 'sylwia.dworaczyk55', 'wizyta', 'szarlota.konopa99', '12', 1, '2024-05-14 08:21:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (146, 'sylwia.dworaczyk55', 'wizyta', 'daniel.sawa65', '0000', 1, '2024-05-14 10:30:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (147, 'sylwia.dworaczyk55', 'rtg', 'prywatnie', '', 1, '');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (148, 'sylwia.dworaczyk55', 'rtg', 'prywatnie', '', 1, '');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (149, 'sylwia.dworaczyk55', 'rtg', 'prywatnie', '', 1, '');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (150, 'sylwia.dworaczyk55', 'rtg', 'prywatnie', '', 1, '');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (151, 'sylwia.dworaczyk55', 'rtg', 'prywatnie', '', 1, '');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (152, 'sylwia.dworaczyk55', 'rtg', 'prywatnie', '', 1, '');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (153, 'sylwia.dworaczyk55', 'rtg', 'prywatnie', '', 1, '');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (154, 'sylwia.dworaczyk55', 'wizyta', 'daniel.sawa65', '696969', 1, '2024-05-14 08:21:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (155, 'sylwia.dworaczyk55', 'wizyta', 'daniel.sawa65', '99999999999', 1, '2024-05-14 09:21:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (156, 'sylwia.baca97', 'rtg', 'prywatnie', '', 0, '');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (157, 'sylwia.dworaczyk55', 'rtg', 'prywatnie', '', 1, '');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (158, 'sylwia.dworaczyk55', 'rtg', 'prywatnie', '', 1, '');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (159, 'sylwia.dworaczyk55', 'rtg', 'nina.owsiany99', '1', 0, '2024-05-14 09:21:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (160, 'sylwia.dworaczyk55', 'rtg', 'prywatnie', '', 1, '');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (161, 'sylwia.dworaczyk55', 'rtg', 'prywatnie', '', 1, '');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (162, 'sylwia.dworaczyk55', 'rtg', 'prywatnie', '', 1, '');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (163, 'sylwia.dworaczyk55', 'rtg', 'daniel.dobosiewicz73', '-5', 0, '2024-05-01 14:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (164, 'sylwia.dworaczyk55', 'wizyta', 'szarlota.konopa99', '12', 0, '2024-05-14 11:00:00');
INSERT INTO med_event (med_event_id, name, describtion, who_prescribed, room, done, time) VALUES (165, 'sylwia.dworaczyk55', 'rtg', 'andrzej.kempka90', '23', 0, '2024-05-14 09:21:00');

-- Table: mor_res
DROP TABLE IF EXISTS mor_res;
CREATE TABLE IF NOT EXISTS mor_res (res_id INTEGER REFERENCES exam (results) ON DELETE CASCADE UNIQUE, rbc INTEGER, hb INTEGER, wbc INTEGER, plt INTEGER);
INSERT INTO mor_res (res_id, rbc, hb, wbc, plt) VALUES (13, 1.1807008067612, 27.34709156193064, 16.43547403323625, 275.30056819206163);
INSERT INTO mor_res (res_id, rbc, hb, wbc, plt) VALUES (14, 9.21767496730898, 4.52406122552242, 18.33655762211482, 490.52624422120414);
INSERT INTO mor_res (res_id, rbc, hb, wbc, plt) VALUES (19, 8.45988792068031, 9.31147601484879, 12.3186945448537, 327.6261060104237);
INSERT INTO mor_res (res_id, rbc, hb, wbc, plt) VALUES (26, 4.07172792798622, 19.56363788445541, 36.2034026383607, 269.40538048520716);
INSERT INTO mor_res (res_id, rbc, hb, wbc, plt) VALUES (30, 9.9649866027628, 21.46296904437639, 18.67800096461517, 175.113883740823);
INSERT INTO mor_res (res_id, rbc, hb, wbc, plt) VALUES (33, 9.29218918333972, 12.5702482762829, 40.78216502864101, 267.3481509631248);
INSERT INTO mor_res (res_id, rbc, hb, wbc, plt) VALUES (41, 1.60599332260616, 19.1038413394781, 34.57829011086075, 572.2111730336334);
INSERT INTO mor_res (res_id, rbc, hb, wbc, plt) VALUES (59, 2.69063130055157, 27.94603588007578, 14.86074354274963, 229.0502103975334);
INSERT INTO mor_res (res_id, rbc, hb, wbc, plt) VALUES (60, 5.02187602459787, 21.89755083016464, 46.50395014973103, 296.402476941812);
INSERT INTO mor_res (res_id, rbc, hb, wbc, plt) VALUES (68, 7.50205056425562, 23.15935596135226, 48.12773599034904, 542.3367687026503);

-- Table: mri_res
DROP TABLE IF EXISTS mri_res;
CREATE TABLE IF NOT EXISTS mri_res (res_id INTEGER REFERENCES exam (results) ON DELETE CASCADE UNIQUE, result TEXT);
INSERT INTO mri_res (res_id, result) VALUES (10, 'zmiany zwyrodnieniowe w 4 kręgu szyjnego');
INSERT INTO mri_res (res_id, result) VALUES (11, 'struktury kostne stawu kolanowego bez zmian pourazowych');
INSERT INTO mri_res (res_id, result) VALUES (17, 'struktury kostne stawu kolanowego bez zmian pourazowych');
INSERT INTO mri_res (res_id, result) VALUES (20, 'struktury kostne stawu kolanowego bez zmian pourazowych');
INSERT INTO mri_res (res_id, result) VALUES (25, 'zmiany zwyrodnieniowe w 4 kręgu szyjnego');
INSERT INTO mri_res (res_id, result) VALUES (40, 'zmiany zwyrodnieniowe w 4 kręgu szyjnego');
INSERT INTO mri_res (res_id, result) VALUES (46, 'zmiany zwyrodnieniowe w 4 kręgu szyjnego');
INSERT INTO mri_res (res_id, result) VALUES (49, 'struktury kostne stawu kolanowego bez zmian pourazowych');
INSERT INTO mri_res (res_id, result) VALUES (63, 'brak obrzęku oraz innych zmian ogniskowych w obrębie płatu ciemieniowego');
INSERT INTO mri_res (res_id, result) VALUES (67, 'brak obrzęku oraz innych zmian ogniskowych w obrębie płatu ciemieniowego');
INSERT INTO mri_res (res_id, result) VALUES (69, 'zmiany zwyrodnieniowe w 4 kręgu szyjnego');

-- Table: patient
DROP TABLE IF EXISTS patient;
CREATE TABLE IF NOT EXISTS patient (pesel varchar (11) PRIMARY KEY ON CONFLICT IGNORE UNIQUE, name varchar (20), familyname varchar (20), city varchar (45), street varchar (45), postcode varchar (6), birthdate date, username varchar (20) REFERENCES account (username) ON DELETE SET NULL MATCH SIMPLE UNIQUE ON CONFLICT IGNORE);
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('79102496350', 'Sylwia', 'Dworaczyk', 'Opole', 'ul. Kazimierza Wielkiego34', '45-001', '1985-07-16', 'sylwia.dworaczyk55');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('96101525490', 'Nina', 'Białkowska', 'Wroclaw', 'ul. Piotrkowska97', '50-001', '1996-10-15', 'nina.białkowska52');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('29040535387', 'Leopold', 'Pułaski', 'Warszawa', 'ul. Podwale47', '00-001', '1929-04-05', 'leopold.pułaski57');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('04021540181', 'Szarlota', 'Kuberski', 'Koszalin', 'ul. Jagiellońska8', '75-001', '1904-02-15', 'szarlota.kuberski65');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('11230736290', 'Paweł', 'Mroczek', 'Ruda Slaska', 'ul. Jana III Sobieskiego9', '41-700', '2011-23-07', 'paweł.mroczek49');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('05280607381', 'Wiara', 'Wojtkiewicz', 'Elblag', 'ul. Grunwaldzka42', '82-300', '2005-28-06', 'wiara.wojtkiewicz96');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('80060314785', 'Zenobiusz', 'Głowa', 'Tarnow', 'ul. Szeroka84', '33-100', '1980-06-03', 'zenobiusz.głowa78');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('51040572158', 'Walerian', 'Kostecka', 'Ruda Slaska', 'ul. Puławska78', '41-700', '1951-04-05', 'walerian.kostecka70');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('47102603100', 'Elwira', 'Konopa', 'Siemianowice Slaskie', 'ul. Krzywa95', '41-100', '1947-10-26', 'elwira.konopa20');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('05250364535', 'Jolanta', 'Pacyna', 'Piotrkow Trybunalski', 'ul. Nowa51', '97-300', '2005-25-03', 'jolanta.pacyna36');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('73091175463', 'Janina', 'Antkowiak', 'Jaworzno', 'ul. Gdańska10', '43-600', '1973-09-11', 'janina.antkowiak31');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('09061262040', 'Janina', 'Konopa', 'Zielona Gora', 'Aleja Jana Pawła II60', '65-001', '1909-06-12', 'janina.konopa53');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('04020592660', 'Wiara', 'Wojtkiewicz', 'Jaworzno', 'Aleja Jana Pawła II65', '43-600', '1904-02-05', 'wiara.wojtkiewicz94');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('66052541915', 'Szarlota', 'Głowa', 'Lodz', 'ul. Zwycięstwa87', '90-001', '1966-05-25', 'szarlota.głowa72');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('56020902233', 'Elwira', 'Węgrzyn', 'Poznan', 'ul. Lutycka33', '60-001', '1956-02-09', 'elwira.węgrzyn26');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('04070260809', 'Janina', 'Baca', 'Opole', 'ul. Konopnickiej14', '45-001', '1904-07-02', 'janina.baca99');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('26031472966', 'Eleonora', 'Dworaczyk', 'Gorzow Wielkopolski', 'ul. Mickiewicza53', '66-001', '1926-03-14', 'eleonora.dworaczyk55');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('05050834351', 'Zenobiusz', 'Jerzak', 'Lublin', 'ul. Wojska Polskiego7', '20-001', '1905-05-08', 'zenobiusz.jerzak62');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('71100211117', 'Borys', 'Pacyna', 'Plock', 'ul. Kopernika41', '09-400', '1971-10-02', 'borys.pacyna38');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('15010380284', 'Wiara', 'Antkowiak', 'Grudziadz', 'ul. Kilińskiego33', '86-300', '1915-01-03', 'wiara.antkowiak76');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('16052762324', 'Jolanta', 'Jerzak', 'Lublin', 'ul. Marszałkowska56', '20-001', '1916-05-27', 'jolanta.jerzak66');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('21230210469', 'Melania', 'Antkowiak', 'Gniezno', 'ul. Kopernika63', '62-200', '2021-23-02', 'melania.antkowiak89');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('11010751972', 'Oktawiusz', 'Podgórny', 'Gorzow Wielkopolski', 'ul. Krucza65', '66-001', '1911-01-07', 'oktawiusz.podgórny24');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('67072870012', 'Janina', 'Juras', 'Poznan', 'ul. Nowa40', '60-001', '1967-07-28', 'janina.juras67');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('73120869699', 'Paweł', 'Mroczka', 'Zielona Gora', 'ul. Marszałkowska37', '65-001', '1973-12-08', 'paweł.mroczka90');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('56010814032', 'Daniel', 'Podgórny', 'Chorzow', 'ul. Krakowska19', '41-500', '1956-01-08', 'daniel.podgórny61');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('75050275973', 'Wiara', 'Baca', 'Jastrzebie-Zdroj', 'ul. Puławska73', '44-330', '1975-05-02', 'wiara.baca13');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('66060917173', 'Sylwia', 'Baca', 'Sosnowiec', 'ul. Krakowska58', '41-200', '1966-06-09', 'sylwia.baca97');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('21281829733', 'Julita', 'Juras', 'Ostrow Wielkopolski', 'ul. Nowa32', '63-400', '2021-28-18', 'julita.juras43');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('78111700889', 'Herbert', 'Sawa', 'Wroclaw', 'ul. Nowy Świat9', '50-001', '1978-11-17', 'herbert.sawa52');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('23241940584', 'Zenobiusz', 'Mroczek', 'Poznan', 'ul. Grunwaldzka47', '60-001', '2023-24-19', 'zenobiusz.mroczek60');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('91020844798', 'August', 'Podgórny', 'Legnica', 'ul. Zwycięstwa72', '59-220', '1991-02-08', 'august.podgórny99');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('71012037258', 'Nina', 'Szalkowski', 'Tarnow', 'ul. Słowackiego87', '33-100', '1971-01-20', 'nina.szalkowski24');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('22021117468', 'Sylwia', 'Przybyliński', 'Ostrow Wielkopolski', 'ul. Aleje Jerozolimskie54', '63-400', '1922-02-11', 'sylwia.przybyliński33');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('08322303719', 'Barbara', 'Antkowiak', 'Radom', 'Aleja Jana Pawła II34', '26-001', '2008-32-23', 'barbara.antkowiak76');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('52032321190', 'Paweł', 'Podgórny', 'Kalisz', 'ul. Krucza67', '62-800', '1952-03-23', 'paweł.podgórny85');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('16321873704', 'Ziemowit', 'Mroczek', 'Legnica', 'ul. Księcia Józefa Poniatowskiego94', '59-220', '2016-32-18', 'ziemowit.mroczek47');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('61071455883', 'Daniel', 'Mroczka', 'Gniezno', 'ul. Lwowska13', '62-200', '1961-07-14', 'daniel.mroczka72');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('61112108749', 'Herbert', 'Pacyna', 'Wroclaw', 'ul. Kopernika100', '50-001', '1961-11-21', 'herbert.pacyna68');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('83072465290', 'Barbara', 'Juras', 'Plock', 'ul. Katedralna78', '09-400', '1983-07-24', 'barbara.juras41');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('77101329345', 'Oktawiusz', 'Głowa', 'Bielsko-Biala', 'ul. Jagiellońska72', '43-300', '1977-10-13', 'oktawiusz.głowa67');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('52051673207', 'Sylwia', 'Pacyna', 'Lubin', 'ul. Krzywa89', '59-300', '1952-05-16', 'sylwia.pacyna74');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('84090173260', 'Borys', 'Mroczek', 'Poznan', 'ul. Mokotowska53', '60-001', '1984-09-01', 'borys.mroczek22');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('18222678286', 'Herbert', 'Rogacka', 'Grudziadz', 'ul. Zwycięstwa2', '86-300', '2018-22-26', 'herbert.rogacka91');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('37031452201', 'Walerian', 'Owsiany', 'Zabrze', 'ul. Dolna45', '41-800', '1937-03-14', 'walerian.owsiany98');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('16211362855', 'Oktawiusz', 'Pacyna', 'Piotrkow Trybunalski', 'ul. Wrocławska1', '97-300', '2016-21-13', 'oktawiusz.pacyna29');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('51010877786', 'Jolanta', 'Mazur', 'Rybnik', 'ul. Grunwaldzka91', '44-200', '1951-01-08', 'jolanta.mazur17');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('49080490507', 'Kazimiera', 'Kostecka', 'Bytom', 'ul. Sobieskiego6', '41-900', '1949-08-04', 'kazimiera.kostecka66');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('29081273082', 'Andrzej', 'Kempka', 'Szczecin', 'ul. Andersa9', '70-001', '1929-08-12', 'andrzej.kempka90');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('94062179321', 'Herbert', 'Węgrzyn', 'Jaworzno', 'ul. Wojska Polskiego3', '43-600', '1994-06-21', 'herbert.węgrzyn42');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('16311105200', 'Ziemowit', 'Rogacka', 'Ostrow Wielkopolski', 'ul. Kopernika11', '63-400', '2016-31-11', 'ziemowit.rogacka82');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('96081665951', 'Leon', 'Rogacka', 'Ostrowiec Swietokrzyski', 'ul. Sobieskiego20', '27-400', '1996-08-16', 'leon.rogacka90');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('23051893474', 'Leon', 'Kempka', 'Tarnow', 'ul. Szeroka97', '33-100', '1923-05-18', 'leon.kempka17');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('50110417236', 'Melania', 'Sawa', 'Zielona Gora', 'ul. Żwirki i Wigury89', '65-001', '1950-11-04', 'melania.sawa91');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('44091543194', 'August', 'Pułaski', 'Walbrzych', 'ul. Sobieskiego80', '58-300', '1944-09-15', 'august.pułaski48');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('23272881544', 'Nina', 'Mroczka', 'Krakow', 'ul. Koszykowa4', '30-001', '2023-27-28', 'nina.mroczka16');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('60051544566', 'Daniel', 'Mroczka', 'Stargard Szczecinski', 'ul. Koszykowa40', '73-110', '1960-05-15', 'daniel.mroczka50');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('90091856471', 'Leopold', 'Białkowska', 'Lubin', 'ul. Katedralna99', '59-300', '1990-09-18', 'leopold.białkowska98');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('10042824854', 'Szarlota', 'Dworaczyk', 'Kalisz', 'ul. Mickiewicza94', '62-800', '1910-04-28', 'szarlota.dworaczyk96');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('13302382202', 'Ziemowit', 'Dobosiewicz', 'Poznan', 'ul. Świętokrzyska82', '60-001', '2013-30-23', 'ziemowit.dobosiewicz17');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('37040184425', 'Borys', 'Szalkowski', 'Legnica', 'ul. Kopernika53', '59-220', '1937-04-01', 'borys.szalkowski49');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('16301744141', 'Szarlota', 'Szablewski', 'Dabrowa Gornicza', 'ul. Wita Stwosza54', '41-300', '2016-30-17', 'szarlota.szablewski58');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('10220409509', 'Elwira', 'Pacyna', 'Plock', 'ul. Jagiellońska60', '09-400', '2010-22-04', 'elwira.pacyna79');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('59061515068', 'Daniel', 'Mazur', 'Bialystok', 'ul. Piękna70', '15-001', '1959-06-15', 'daniel.mazur60');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('00010460892', 'Daniel', 'Mazur', 'Czestochowa', 'ul. Andersa68', '42-001', '1900-01-04', 'daniel.mazur77');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('81082501315', 'Kunegunda', 'Owsiany', 'Bytom', 'ul. Nowa89', '41-900', '1981-08-25', 'kunegunda.owsiany68');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('69010921848', 'Elwira', 'Jerzak', 'Lodz', 'ul. Lwowska98', '90-001', '1969-01-09', 'elwira.jerzak22');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('04111387171', 'Walerian', 'Mroczek', 'Piotrkow Trybunalski', 'ul. Nowowiejska86', '97-300', '1904-11-13', 'walerian.mroczek61');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('41020956672', 'Sylwia', 'Juras', 'Legnica', 'ul. Piłsudskiego51', '59-220', '1941-02-09', 'sylwia.juras60');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('98062025095', 'Janina', 'Jerzak', 'Szczecin', 'ul. Wojska Polskiego70', '70-001', '1998-06-20', 'janina.jerzak60');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('50110345007', 'Herbert', 'Kuberski', 'Poznan', 'ul. Piękna94', '60-001', '1950-11-03', 'herbert.kuberski94');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('49070141594', 'Szarlota', 'Pacyna', 'Poznan', 'ul. Wrocławska88', '60-001', '1949-07-01', 'szarlota.pacyna89');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('00281830299', 'Barbara', 'Juras', 'Radom', 'ul. Wrocławska24', '26-001', '2000-28-18', 'barbara.juras22');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('13112447030', 'Zenobiusz', 'Kempka', 'Tarnow', 'ul. Puławska67', '33-100', '1913-11-24', 'zenobiusz.kempka66');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('44111978221', 'Ludomir', 'Jerzak', 'Wroclaw', 'ul. Jagiellońska55', '50-001', '1944-11-19', 'ludomir.jerzak32');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('21072876713', 'Nina', 'Owsiany', 'Bydgoszcz', 'ul. Kazimierza Wielkiego29', '85-001', '1921-07-28', 'nina.owsiany99');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('36101068748', 'Jolanta', 'Dobosiewicz', 'Chorzow', 'ul. Nowowiejska52', '41-500', '1936-10-10', 'jolanta.dobosiewicz14');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('93050628966', 'Kazimiera', 'Podgórny', 'Sosnowiec', 'ul. Katedralna64', '41-200', '1993-05-06', 'kazimiera.podgórny15');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('64110319580', 'Katarzyna', 'Rogacka', 'Piotrkow Trybunalski', 'ul. Jagiellońska8', '97-300', '1964-11-03', 'katarzyna.rogacka41');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('59112567505', 'Walerian', 'Juras', 'Walbrzych', 'ul. Sienkiewicza98', '58-300', '1959-11-25', 'walerian.juras14');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('28010732173', 'Leopold', 'Dobosiewicz', 'Torun', 'ul. Gdańska51', '87-100', '1928-01-07', 'leopold.dobosiewicz88');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('68010133420', 'Herbert', 'Baca', 'Siemianowice Slaskie', 'ul. Mennica63', '41-100', '1968-01-01', 'herbert.baca20');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('53080209816', 'Leopold', 'Juras', 'Dabrowa Gornicza', 'ul. Słowackiego74', '41-300', '1953-08-02', 'leopold.juras43');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('37110450836', 'Nina', 'Mroczka', 'Ostrowiec Swietokrzyski', 'ul. Piotrkowska85', '27-400', '1937-11-04', 'nina.mroczka77');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('37042712361', 'Leon', 'Konopa', 'Lublin', 'ul. Katedralna22', '20-001', '1937-04-27', 'leon.konopa33');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('19120690099', 'Katarzyna', 'Dobosiewicz', 'Chorzow', 'ul. Piotrkowska97', '41-500', '1919-12-06', 'katarzyna.dobosiewicz77');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('44102295834', 'Barbara', 'Antkowiak', 'Lublin', 'ul. Konopnickiej8', '20-001', '1944-10-22', 'barbara.antkowiak94');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('24040317261', 'Borys', 'Szablewski', 'Grudziadz', 'ul. Św. Wojciecha74', '86-300', '1924-04-03', 'borys.szablewski51');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('42011963202', 'Ludomir', 'Mroczek', 'Kielce', 'Aleja Jana Pawła II75', '25-001', '1942-01-19', 'ludomir.mroczek18');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('91061224991', 'Sylwester', 'Kuberski', 'Radom', 'ul. Krucza15', '26-001', '1991-06-12', 'sylwester.kuberski59');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('87070294409', 'Daniel', 'Przybyliński', 'Chorzow', 'ul. Krakowska43', '41-500', '1987-07-02', 'daniel.przybyliński40');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('20080363015', 'August', 'Owsiany', 'Koszalin', 'ul. Mokotowska53', '75-001', '1920-08-03', 'august.owsiany13');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('68121534736', 'Eleonora', 'Głowa', 'Tychy', 'ul. Świętokrzyska11', '43-100', '1968-12-15', 'eleonora.głowa46');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('23270342168', 'Leopold', 'Podgórny', 'Sosnowiec', 'Aleja Jana Pawła II100', '41-200', '2023-27-03', 'leopold.podgórny97');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('19090840313', 'Borys', 'Węgrzyn', 'Kalisz', 'ul. Konopnickiej74', '62-800', '1919-09-08', 'borys.węgrzyn56');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('66020682068', 'Leon', 'Szablewski', 'Katowice', 'ul. Lutycka5', '40-001', '1966-02-06', 'leon.szablewski73');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('13020258665', 'Barbara', 'Węgrzyn', 'Ostrow Wielkopolski', 'ul. Krucza84', '63-400', '1913-02-02', 'barbara.węgrzyn29');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('73102389702', 'Nina', 'Szalkowski', 'Kalisz', 'ul. Nowa2', '62-800', '1973-10-23', 'nina.szalkowski65');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('56011665927', 'Daniel', 'Ligas', 'Bydgoszcz', 'ul. Aleje Jerozolimskie62', '85-001', '1956-01-16', 'daniel.ligas82');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('52071754447', 'Beata', 'Mroczka', 'Bytom', 'ul. Kopernika80', '41-900', '1952-07-17', 'beata.mroczka52');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('92031517958', 'Nina', 'Pułaski', 'Olsztyn', 'ul. Świętokrzyska39', '10-001', '1992-03-15', 'nina.pułaski57');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('43121616941', 'Nina', 'Pacyna', 'Szczecin', 'ul. Dolna30', '70-001', '1943-12-16', 'nina.pacyna47');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('02210377758', 'Jolanta', 'Bien', 'Kielce', 'ul. Podwale28', '25-001', '2002-21-03', 'jolanta.bien17');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('26010755130', 'Herbert', 'Antkowiak', 'Lublin', 'ul. Krakowska70', '20-001', '1926-01-07', 'herbert.antkowiak50');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('11312539670', 'Daniel', 'Węgrzyn', 'Myslowice', 'ul. Krucza23', '41-400', '2011-31-25', 'daniel.węgrzyn44');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('61061013668', 'Zenobiusz', 'Mazur', 'Siemianowice Slaskie', 'ul. Konopnickiej95', '41-100', '1961-06-10', 'zenobiusz.mazur62');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('10081315142', 'August', 'Sawa', 'Plock', 'ul. Armii Krajowej17', '09-400', '1910-08-13', 'august.sawa13');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('02061212312', 'Oktawiusz', 'Białkowska', 'Walbrzych', 'ul. Kazimierza Wielkiego82', '58-300', '1902-06-12', 'oktawiusz.białkowska34');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('36110834392', 'Sylwester', 'Dobosiewicz', 'Lubin', 'ul. Krakowska87', '59-300', '1936-11-08', 'sylwester.dobosiewicz77');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('23260695494', 'Herbert', 'Juras', 'Gdynia', 'ul. Aleje Jerozolimskie90', '81-001', '2023-26-06', 'herbert.juras24');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('91050176113', 'Sylwia', 'Kostecka', 'Radom', 'ul. Jana III Sobieskiego50', '26-001', '1991-05-01', 'sylwia.kostecka92');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('05251930366', 'August', 'Kostecka', 'Rzeszow', 'ul. Sobieskiego68', '35-001', '2005-25-19', 'august.kostecka82');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('58072530659', 'Melania', 'Antkowiak', 'Tychy', 'ul. Piłsudskiego83', '43-100', '1958-07-25', 'melania.antkowiak91');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('60112711535', 'Andrzej', 'Kostecka', 'Katowice', 'ul. Piotrkowska3', '40-001', '1960-11-27', 'andrzej.kostecka10');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('23062357105', 'Daniel', 'Konopa', 'Radom', 'ul. Wita Stwosza60', '26-001', '1923-06-23', 'daniel.konopa98');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('55040711724', 'Elwira', 'Kostecka', 'Koszalin', 'ul. Szeroka94', '75-001', '1955-04-07', 'elwira.kostecka46');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('89042271041', 'Romuald', 'Wojtkiewicz', 'Walbrzych', 'ul. Lwowska100', '58-300', '1989-04-22', 'romuald.wojtkiewicz85');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('82101642660', 'Katarzyna', 'Głowa', 'Koszalin', 'ul. Armii Krajowej21', '75-001', '1982-10-16', 'katarzyna.głowa77');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('39100381665', 'Ludomir', 'Szalkowski', 'Ruda Slaska', 'ul. Katedralna79', '41-700', '1939-10-03', 'ludomir.szalkowski44');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('01070592695', 'Kunegunda', 'Rogacka', 'Radom', 'ul. Podwale54', '26-001', '1901-07-05', 'kunegunda.rogacka51');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('89070976385', 'Paweł', 'Antkowiak', 'Myslowice', 'ul. Świętokrzyska30', '41-400', '1989-07-09', 'paweł.antkowiak58');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('35041500888', 'Leopold', 'Mroczek', 'Bielsko-Biala', 'ul. Jagiellońska70', '43-300', '1935-04-15', 'leopold.mroczek18');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('50021343378', 'Sylwia', 'Kostuch', 'Lubin', 'ul. Gdańska70', '59-300', '1950-02-13', 'sylwia.kostuch79');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('53091119720', 'Barbara', 'Kostuch', 'Jastrzebie-Zdroj', 'ul. Sienkiewicza76', '44-330', '1953-09-11', 'barbara.kostuch30');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('51111072411', 'Kazimiera', 'Jerzak', 'Ruda Slaska', 'ul. Piotrkowska56', '41-700', '1951-11-10', 'kazimiera.jerzak50');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('48051800385', 'Barbara', 'Głowa', 'Opole', 'ul. Lwowska2', '45-001', '1948-05-18', 'barbara.głowa27');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('84081350645', 'Julita', 'Białkowska', 'Bielsko-Biala', 'ul. Nowy Świat89', '43-300', '1984-08-13', 'julita.białkowska15');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('13210536236', 'Sylwia', 'Szablewski', 'Lublin', 'ul. Katedralna65', '20-001', '2013-21-05', 'sylwia.szablewski78');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('86021823550', 'Leon', 'Rogacka', 'Zielona Gora', 'ul. Jagiellońska4', '65-001', '1986-02-18', 'leon.rogacka39');
INSERT INTO patient (pesel, name, familyname, city, street, postcode, birthdate, username) VALUES ('21120762900', 'Ziemowit', 'Pacyna', 'Rzeszow', 'ul. Kilińskiego56', '35-001', '1921-12-07', 'ziemowit.pacyna69');

-- Table: prescribtion
DROP TABLE IF EXISTS prescribtion;
CREATE TABLE IF NOT EXISTS prescribtion (pres_id INTEGER REFERENCES med_event (med_event_id) ON DELETE CASCADE, medicine varchar (45), dose TEXT, exp_date date);
INSERT INTO prescribtion (pres_id, medicine, dose, exp_date) VALUES (12, 'Sertralina', 'raz dziennie przez miesiąc', '2025-04-11');
INSERT INTO prescribtion (pres_id, medicine, dose, exp_date) VALUES (26, 'Insulina', 'raz dziennie przez dwa tygodnie', '2025-04-11');
INSERT INTO prescribtion (pres_id, medicine, dose, exp_date) VALUES (31, 'Warfaryna', 'dwa razy dziennie przez dwa tygodnie', '2025-04-11');
INSERT INTO prescribtion (pres_id, medicine, dose, exp_date) VALUES (35, 'Escitalopram', 'raz dziennie przez miesiąc', '2025-04-11');
INSERT INTO prescribtion (pres_id, medicine, dose, exp_date) VALUES (48, 'Clatra', 'dwa razy dziennie przez tydzień', '2025-04-11');
INSERT INTO prescribtion (pres_id, medicine, dose, exp_date) VALUES (61, 'Insulina', 'raz dziennie przez tydzień', '2025-04-11');
INSERT INTO prescribtion (pres_id, medicine, dose, exp_date) VALUES (77, 'Deksametazon', 'raz dziennie przez miesiąc', '2025-04-11');
INSERT INTO prescribtion (pres_id, medicine, dose, exp_date) VALUES (102, 'Deksametazon', 'dwa razy dziennie przez tydzień', '2025-04-11');

-- Table: procedure
DROP TABLE IF EXISTS procedure;
CREATE TABLE IF NOT EXISTS procedure (procedure_id INTEGER REFERENCES med_event (med_event_id) ON DELETE CASCADE, who_performs varchar (20) REFERENCES account (username) ON DELETE CASCADE, "when" date, room varchar (40));
INSERT INTO procedure (procedure_id, who_performs, "when", room) VALUES (11, 'romuald.bien38', '2025-02-17 08:00:00', '292');
INSERT INTO procedure (procedure_id, who_performs, "when", room) VALUES (28, 'julita.głowa29', '2022-04-01 07:00:00', '185');
INSERT INTO procedure (procedure_id, who_performs, "when", room) VALUES (40, 'daniel.sawa65', '2026-09-11 11:00:00', '294');
INSERT INTO procedure (procedure_id, who_performs, "when", room) VALUES (49, 'julita.głowa29', '2025-02-09 09:00:00', '218');
INSERT INTO procedure (procedure_id, who_performs, "when", room) VALUES (62, 'julita.głowa29', '2022-04-05 10:00:00', '152');
INSERT INTO procedure (procedure_id, who_performs, "when", room) VALUES (64, 'sylwester.wojtkiewicz36', '2026-01-22 06:00:00', '208');
INSERT INTO procedure (procedure_id, who_performs, "when", room) VALUES (72, 'andrzej.kuberski45', '2023-09-02 08:00:00', '297');
INSERT INTO procedure (procedure_id, who_performs, "when", room) VALUES (93, 'daniel.konopa54', '2024-05-15 08:00:00', '239');
INSERT INTO procedure (procedure_id, who_performs, "when", room) VALUES (94, 'sylwester.wojtkiewicz36', '2026-04-13 15:00:00', '273');
INSERT INTO procedure (procedure_id, who_performs, "when", room) VALUES (96, 'daniel.dobosiewicz73', '2026-11-11 17:00:00', '270');
INSERT INTO procedure (procedure_id, who_performs, "when", room) VALUES (106, 'kazimiera.dobosiewicz23', '2023-05-09 16:00:00', '293');

-- Table: rtg_res
DROP TABLE IF EXISTS rtg_res;
CREATE TABLE IF NOT EXISTS rtg_res (res_id INTEGER REFERENCES exam (results) ON DELETE CASCADE UNIQUE, result TEXT);
INSERT INTO rtg_res (res_id, result) VALUES (12, 'złamana kość przedramienia z przemieszczeniem');
INSERT INTO rtg_res (res_id, result) VALUES (15, 'obraz zmian radiologicznych może wskazywać na zapalenie oskrzeli i płuc');
INSERT INTO rtg_res (res_id, result) VALUES (16, 'obraz zmian radiologicznych może wskazywać na zapalenie oskrzeli i płuc');
INSERT INTO rtg_res (res_id, result) VALUES (21, 'pola płucne bez zagęszczeń ogniskowych');
INSERT INTO rtg_res (res_id, result) VALUES (22, 'pola płucne bez zagęszczeń ogniskowych');
INSERT INTO rtg_res (res_id, result) VALUES (27, 'obraz zmian radiologicznych może wskazywać na zapalenie oskrzeli i płuc');
INSERT INTO rtg_res (res_id, result) VALUES (28, 'obraz zmian radiologicznych może wskazywać na zapalenie oskrzeli i płuc');
INSERT INTO rtg_res (res_id, result) VALUES (29, 'pola płucne bez zagęszczeń ogniskowych');
INSERT INTO rtg_res (res_id, result) VALUES (34, 'pola płucne bez zagęszczeń ogniskowych');
INSERT INTO rtg_res (res_id, result) VALUES (38, 'pola płucne bez zagęszczeń ogniskowych');
INSERT INTO rtg_res (res_id, result) VALUES (42, 'pola płucne bez zagęszczeń ogniskowych');
INSERT INTO rtg_res (res_id, result) VALUES (43, 'złamana kość przedramienia z przemieszczeniem');
INSERT INTO rtg_res (res_id, result) VALUES (44, 'złamana kość przedramienia z przemieszczeniem');
INSERT INTO rtg_res (res_id, result) VALUES (48, 'obraz zmian radiologicznych może wskazywać na zapalenie oskrzeli i płuc');
INSERT INTO rtg_res (res_id, result) VALUES (51, 'złamana kość przedramienia z przemieszczeniem');
INSERT INTO rtg_res (res_id, result) VALUES (53, 'obraz zmian radiologicznych może wskazywać na zapalenie oskrzeli i płuc');
INSERT INTO rtg_res (res_id, result) VALUES (54, 'obraz zmian radiologicznych może wskazywać na zapalenie oskrzeli i płuc');
INSERT INTO rtg_res (res_id, result) VALUES (55, 'obraz zmian radiologicznych może wskazywać na zapalenie oskrzeli i płuc');
INSERT INTO rtg_res (res_id, result) VALUES (57, 'obraz zmian radiologicznych może wskazywać na zapalenie oskrzeli i płuc');
INSERT INTO rtg_res (res_id, result) VALUES (65, 'pola płucne bez zagęszczeń ogniskowych');
INSERT INTO rtg_res (res_id, result) VALUES (72, 'pola płucne bez zagęszczeń ogniskowych');
INSERT INTO rtg_res (res_id, result) VALUES (73, 'pola płucne bez zagęszczeń ogniskowych');

-- Table: sched_ev
DROP TABLE IF EXISTS sched_ev;
CREATE TABLE IF NOT EXISTS sched_ev (sched_id INTEGER REFERENCES schedule (sched_id) ON DELETE CASCADE, med_ev_id INTEGER REFERENCES med_event (med_event_id) ON DELETE CASCADE);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (1, 115);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (1, 114);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (1, 113);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (1, 112);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (1, 111);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (1, 110);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (4, 116);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (4, 117);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (4, 118);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (4, 119);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (4, 120);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (4, 121);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 122);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 123);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (1, 124);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (1, 125);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (1, 126);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (1, 127);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 122);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 122);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (2, 74);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (4, 128);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (4, 129);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 130);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (4, 131);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 132);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 133);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 134);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 135);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 136);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 137);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 138);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 139);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 140);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 141);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 142);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 143);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 144);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 145);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (1, 146);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (4294967297, 147);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 148);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 149);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 150);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 151);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 152);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 153);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (1, 154);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (1, 155);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 156);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 157);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 158);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 159);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 4634766966517661696);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 4634766966517661696);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 159);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (0, 160);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 161);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 162);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 163);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (4, 164);
INSERT INTO sched_ev (sched_id, med_ev_id) VALUES (5, 165);

-- Table: schedule
DROP TABLE IF EXISTS schedule;
CREATE TABLE IF NOT EXISTS schedule (who varchar (20) REFERENCES account (username) ON DELETE CASCADE, sched_id INTEGER PRIMARY KEY, start datetime, end datetime, type varchar (10), active tiny int);
INSERT INTO schedule (who, sched_id, start, end, type, active) VALUES ('daniel.sawa65', 1, '2024-05-14 06:00:00', '2024-05-14 14:00:00', 'wizyta', 1);
INSERT INTO schedule (who, sched_id, start, end, type, active) VALUES ('daniel.sawa65', 2, '2024-05-14 06:00:00', '2024-05-14 14:00:00', 'zabieg', 1);
INSERT INTO schedule (who, sched_id, start, end, type, active) VALUES ('szarlota.konopa99', 4, '2024-05-14 06:00:00', '2024-05-14 14:00:00', 'wizyta', 1);
INSERT INTO schedule (who, sched_id, start, end, type, active) VALUES ('szarlota.konopa99', 5, '2024-05-15 06:00:00', '2024-05-15 14:00:00', 'rtg', 1);

-- Table: usg_res
DROP TABLE IF EXISTS usg_res;
CREATE TABLE IF NOT EXISTS usg_res (res_id INTEGER REFERENCES exam (results) ON DELETE CASCADE UNIQUE, result TEXT);
INSERT INTO usg_res (res_id, result) VALUES (23, 'drogi żółciowe nieposzerzone');
INSERT INTO usg_res (res_id, result) VALUES (24, 'brak niepokojących zmian');
INSERT INTO usg_res (res_id, result) VALUES (31, 'powiększona śledziona');
INSERT INTO usg_res (res_id, result) VALUES (32, 'płód rozwija się prawidłowo');
INSERT INTO usg_res (res_id, result) VALUES (45, 'drogi żółciowe nieposzerzone');
INSERT INTO usg_res (res_id, result) VALUES (47, 'powiększona śledziona');
INSERT INTO usg_res (res_id, result) VALUES (50, 'brak niepokojących zmian');
INSERT INTO usg_res (res_id, result) VALUES (52, 'płód rozwija się prawidłowo');
INSERT INTO usg_res (res_id, result) VALUES (62, 'drogi żółciowe nieposzerzone');
INSERT INTO usg_res (res_id, result) VALUES (66, 'drogi żółciowe nieposzerzone');
INSERT INTO usg_res (res_id, result) VALUES (70, 'drogi żółciowe nieposzerzone');

-- View: doctors
DROP VIEW IF EXISTS doctors;
CREATE VIEW IF NOT EXISTS doctors as
select * from account where type = 'doctor';

-- View: exams
DROP VIEW IF EXISTS exams;
CREATE VIEW IF NOT EXISTS exams as
SELECT med_event.med_event_id,med_event.name AS patient_name,med_event.describtion,account.name AS prescriber_name,account.familyname AS prescriber_familyname,account.username AS prescriber,exam.who_performs AS exam_who,exam_account.name AS exam_name,exam_account.familyname AS exam_familyname,exam."when",exam.room, done, med_event.time as time FROM med_event JOIN account ON med_event.who_prescribed = account.username JOIN exam ON med_event.med_event_id = exam.exam_id JOIN account AS exam_account ON exam.who_performs = exam_account.username;

-- View: patient_ekg
DROP VIEW IF EXISTS patient_ekg;
CREATE VIEW IF NOT EXISTS patient_ekg AS select med_event.med_event_id, med_event.name,med_event.describtion,med_event.who_prescribed,exam.who_performs,exam."when",ekg_res.rhytm,ekg_res.pr_delay,ekg_res.qrs
from med_event join exam on med_event.med_event_id = exam.exam_id join ekg_res on exam.results = ekg_res.res_id;

-- View: patient_mor
DROP VIEW IF EXISTS patient_mor;
CREATE VIEW IF NOT EXISTS patient_mor as
select med_event.med_event_id, med_event.name,med_event.describtion,med_event.who_prescribed,exam.who_performs,exam."when",mor_res.rbc,mor_res.hb,mor_res.wbc,mor_res.plt from
med_event join exam on med_event.med_event_id = exam.exam_id join mor_res on exam.results = mor_res.res_id;

-- View: patient_mri
DROP VIEW IF EXISTS patient_mri;
CREATE VIEW IF NOT EXISTS patient_mri as
select med_event.med_event_id, med_event.name,med_event.describtion,med_event.who_prescribed,exam.who_performs,exam."when",mri_res.result from
med_event join exam on med_event.med_event_id = exam.exam_id join mri_res on exam.results = mri_res.res_id;

-- View: patient_rtg
DROP VIEW IF EXISTS patient_rtg;
CREATE VIEW IF NOT EXISTS patient_rtg as
select med_event.med_event_id, med_event.name,med_event.describtion,med_event.who_prescribed,exam.who_performs,exam."when",rtg_res.result from
med_event join exam on med_event.med_event_id = exam.exam_id join rtg_res on exam.results = rtg_res.res_id;

-- View: patient_usg
DROP VIEW IF EXISTS patient_usg;
CREATE VIEW IF NOT EXISTS patient_usg as
select med_event.med_event_id, med_event.name,med_event.describtion,med_event.who_prescribed,exam.who_performs,exam."when",usg_res.result from
med_event join exam on med_event.med_event_id = exam.exam_id join usg_res on exam.results = usg_res.res_id;

-- View: patients
DROP VIEW IF EXISTS patients;
CREATE VIEW IF NOT EXISTS patients as
select * from patient join account on account.username = patient.username where type = 'patient';

-- View: prescribtions
DROP VIEW IF EXISTS prescribtions;
CREATE VIEW IF NOT EXISTS prescribtions as
select med_event.med_event_id, med_event.name, med_event.describtion,med_event.who_prescribed,
med_event.room, med_event.done, med_event.time, prescribtion.medicine, prescribtion.dose,
prescribtion.exp_date
from med_event join prescribtion on med_event.med_event_id = prescribtion.pres_id;

-- View: procedures
DROP VIEW IF EXISTS procedures;
CREATE VIEW IF NOT EXISTS procedures as 
SELECT med_event.med_event_id,med_event.name AS patient_name,med_event.describtion,account.name AS prescriber_name,
account.familyname AS prescriber_familyname,account.username AS prescriber,
procedure.who_performs AS exam_who,exam_account.name AS exam_name,exam_account.familyname AS exam_familyname,procedure."when",procedure.room, med_event.done, med_event.time as time 
FROM med_event JOIN account ON med_event.who_prescribed = account.username JOIN procedure ON med_event.med_event_id = procedure.procedure_id
JOIN account AS exam_account ON procedure.who_performs = exam_account.username;

-- View: referal_exam
DROP VIEW IF EXISTS referal_exam;
CREATE VIEW IF NOT EXISTS referal_exam as
select med_event.med_event_id from med_event left join exam on med_event.med_event_id = exam.exam_id
where exam.exam_id is null and med_event.who_prescribed <> 'prywatnie' and 
med_event.describtion in ('rtg','usg','mri','morfologia','ekg');

-- View: referal_proc
DROP VIEW IF EXISTS referal_proc;
CREATE VIEW IF NOT EXISTS referal_proc as
select med_event.med_event_id from med_event left join procedure on med_event.med_event_id = procedure.procedure_id
where procedure.procedure_id is null and med_event.who_prescribed <> 'prywatnie' and med_event.describtion = 'zabieg';

-- View: regs
DROP VIEW IF EXISTS regs;
CREATE VIEW IF NOT EXISTS regs as
select * from account where type = 'registration';

-- View: scheduled_events
DROP VIEW IF EXISTS scheduled_events;
CREATE VIEW IF NOT EXISTS scheduled_events as
select schedule.who,schedule.sched_id, schedule.type,med_event.med_event_id,med_event.name,med_event.describtion,
med_event.done, med_event.room, med_event.time, med_event.who_prescribed
from schedule join sched_ev on schedule.sched_id = sched_ev.sched_id
join med_event on sched_ev.med_ev_id = med_event.med_event_id;

-- View: scheduled_exams
DROP VIEW IF EXISTS scheduled_exams;
CREATE VIEW IF NOT EXISTS scheduled_exams as
select schedule.who,schedule.sched_id, schedule.type,med_event.med_event_id,med_event.name,med_event.describtion,
med_event.done, med_event.room, exam."when", med_event.who_prescribed
from schedule join sched_ev on schedule.sched_id = sched_ev.sched_id
join med_event on sched_ev.med_ev_id = med_event.med_event_id
join exam on med_event.med_event_id = exam.exam_id;

-- View: users
DROP VIEW IF EXISTS users;
CREATE VIEW IF NOT EXISTS users AS select username, password, type from account;

-- View: visits
DROP VIEW IF EXISTS visits;
CREATE VIEW IF NOT EXISTS visits as 
select med_event.med_event_id, med_event.name as patient_name, describtion, who_prescribed,account.name as doc_name,account.familyname as doc_fn, room,med_event.time, med_event.done from med_event join account on med_event.who_prescribed = account.username where describtion = 'wizyta';

COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
